// BitcoinExchange.hpp

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>

class BitcoinExchange {
private:
    std::map<std::string, float> btcDatabase;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void loadBTCDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);
};

#endif
