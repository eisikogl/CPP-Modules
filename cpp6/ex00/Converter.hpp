#ifndef CONVERTER_HPP
#define CONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>

class ScalarConverter
{
    private:
        static std::string input;

        static char _charValue;
        static int _intValue;
        static float _floatValue;
        static double _doubleValue;
        static long long int _tmpInt;
        static int precisionCount;

        static bool isChar(std::string str);
        static bool isInt(std::string str);
        static bool isFloat(std::string str);
        static bool isDouble(std::string str);
        static bool isImpossible(std::string str);

        static void convertFromChar(std::string str);
        static void convertFromInt(std::string str);
        static void convertFromFloat(std::string str);
        static void convertFromDouble(std::string str);

        static void displayResult();
    public:
        static void convert(const std::string str);
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator = (const ScalarConverter &assign);
        ~ScalarConverter();
};

#endif