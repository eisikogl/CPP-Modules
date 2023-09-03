#include "BitcoinExchange.hpp"
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <climits>

BitcoinExchange::BitcoinExchange()
{}
BitcoinExchange::~BitcoinExchange()
{}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : btcDatabase(other.btcDatabase) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) 
{
    if (this != &other) 
    {
        btcDatabase = other.btcDatabase;
    }
    return *this;
}

bool isValidDateFormat(const std::string& date)
{
    if(date.length() != 10)
        return false;
    if(date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 4; ++i) 
        if (!isdigit(date[i])) 
            return false;
    for (int i = 5; i < 7; ++i)
        if (!isdigit(date[i]))
            return false;
    for (int i = 8; i < 10; ++i)
        if (!isdigit(date[i]))
            return false;
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if(month == 2 && day > 28)
        return false;
    if(month <= 7 && month % 2 == 0 && day > 30)
        return false;
    if((month > 7 && month <= 12) && month % 2 == 1 && day > 30)
        return false;
    return true;
}

void BitcoinExchange::loadBTCDatabase(const std::string& filename) 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) 
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }

    std::string line, date;
    float value;

    while (getline(file, line)) 
    {
        std::istringstream ss(line);
        getline(ss, date, ',');
        ss >> value;
        btcDatabase[date] = value;
    }

    file.close();
}

void BitcoinExchange::processInputFile(const std::string& filename) 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) 
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return;
    }

    std::string line, date;
    float amount;


    while (getline(file, line)) 
    {
        if (line == "date | value")
            continue;
        std::istringstream ss(line);
        getline(ss, date, '|');
        ss >> amount;

        date.erase(0, date.find_first_not_of(' '));
        date.erase(date.find_last_not_of(' ') + 1);
        if (date.empty() || ss.fail()) 
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if(!(amount > 0 && amount < 1000))
        {
            if(amount < 0.0f)
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        if(!isValidDateFormat(date))
        {
            std::cerr << "Error: Invalid Date Format => " << date << std::endl;
            continue;
        }
       

        if (btcDatabase.find(date) != btcDatabase.end()) 
        {
            float value = btcDatabase[date];
            float result = amount * value;
            std::cout << date << " => " << amount << " = " << result << std::endl;
        }
        else
        {
            std::map<std::string,float>::iterator it = btcDatabase.lower_bound(date);

            if(it != btcDatabase.begin())
            {
                if(it == btcDatabase.end() || it->first != date)
                    --it;
                std::string closestDate = it->first;
                float value = btcDatabase[closestDate];
                float result = amount * value;
                std::cout << date << " => " << amount << " = " << result << std::endl;
            }
            else
            {
                std::cerr << "Error: Date " << date << " not found in BTC database." << std::endl;
            }
        }
    }

    file.close();
}