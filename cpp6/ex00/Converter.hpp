#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>

class ScalarConverter
{
    private:
        std::string input;

        char _charValue;
        int _intValue;
        float _floatValue;
        double _doubleValue;
        long long int _tmpInt;
        int precisionCount;

        bool isChar(std::string str);
        bool isInt(std::string str);
        bool isFloat(std::string str);
        bool isDouble(std::string str);
        bool isImpossible(std::string str);

        void convertFromChar(std::string str);
        void convertFromInt(std::string str);
        void convertFromFloat(std::string str);
        void convertFromDouble(std::string str);

        void displayResult();
    public:
        static void convert(const std::string str);
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator = (const ScalarConverter &assign);
        ~ScalarConverter();
};

#endif