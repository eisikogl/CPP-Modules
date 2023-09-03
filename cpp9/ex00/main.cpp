#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) 
{
    if (argc != 2) 
    {
        std::cout << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange btcExchange;
    btcExchange.loadBTCDatabase("data.csv");
    btcExchange.processInputFile(argv[1]);

    return 0;
}