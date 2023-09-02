#include <map>
#include <vector>
#include <string>

class BitcoinExchange {
private:
    std::map<std::string, float> btcPrices;  // To store the bitcoin prices from the CSV database

public:
    BitcoinExchange(const std::string& csvFilename);  // Constructor to initialize the database

    // Method to read the CSV database
    void readCSV(const std::string& filename);

    // Method to calculate the bitcoin value for a given date and amount
    float calculateValue(const std::string& date, float amount);

    // Method to process the input file and print the results
    void processInput(const std::string& inputFilename);
};
