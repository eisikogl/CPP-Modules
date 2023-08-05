#include "Converter.hpp"
#include <climits>
#include <sstream>

// char not working properly
// = operator fix
// fixed static class
// integers not working properly - convertfromint
// char calling int not working

//orthodox

	char ScalarConverter::_charValue = 0;
	//int ScalarConverter::_intValue = 0;
	float ScalarConverter::_floatValue = 0.0f;
	double ScalarConverter::_doubleValue = 0.0;
	int ScalarConverter::precisionCount = 0;
	double ScalarConverter::_tmpInt = 0;
	std::string ScalarConverter::input;

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &assign)
{
	(void)assign;
	return *this;
}

ScalarConverter::~ScalarConverter()
{

}

//convert static method

void ScalarConverter::convert(const std::string str)
{
    input = str;
	if (ScalarConverter::isChar(input))
		ScalarConverter::convertFromChar(input);
	else if (ScalarConverter::isInt(input))
		ScalarConverter::convertFromInt(input);
	else if (ScalarConverter::isFloat(input))
		ScalarConverter::convertFromFloat(input);
	else if (ScalarConverter::isDouble(input))
		ScalarConverter::convertFromDouble(input);
    else if (ScalarConverter::isImpossible(input))
	{
		if (!input.compare("nan") || !input.compare("+inf") || !input.compare("-inf"))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << input << "f" << std::endl;
			std::cout << "double: " << input << std::endl;
		}
		else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << input << std::endl;
			std::cout << "double: " << input << std::endl;
		}
    }
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

//conversion methods

bool ScalarConverter::isChar(std::string str)
{
    if(str.size() != 1)
		return false;
	if(isdigit(str[0]))
		return false;
    char c = str[0];
	if(isprint(c) || !isdigit(c))
	{
		std::cout << "im called: is char" << std::endl;
        return true;
	}
    else
        return false;
}

bool ScalarConverter::isInt(std::string str)
{
	if (str[0] == '-')
		str.erase(0, 1);
	if (!isdigit(str[0]))
		return (false);
	for (unsigned long long i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	std::cout << "im called: is Int" << std::endl;
	return (true);
}

bool ScalarConverter::isFloat(std::string str)
{
    int i = 0;

    if(str[i] == '-')
        i++;
    if(!isdigit(str[i]))
        return (false);
    while(isdigit(str[i]))
        i++;
    if(str[i] != '.')
        return (false);
    i++;
    if (!isdigit(str[i]))
        return (false);
    while(isdigit(str[i]))
    {
        i++;
        precisionCount++;
    }
    if(str[i] != 'f')
        return (false);
    i++;
    if(str[i])
        return (false);
    return (true);
}

bool ScalarConverter::isDouble(std::string str)
{
    int i = 0;
    if(str[i] == '-')
        i++;
    if(!isdigit(str[i]))
        return (false);
    while(isdigit(str[i]))
        i++;
    if(str[i] != '.')
        return (false);
    i++;
    if(!isdigit(str[i]))
        return (false);
    while(isdigit(str[i]))
        i++;
    if(str[i])
        return (false);
    return true;
}

bool ScalarConverter::isImpossible(std::string str)
{
    if (!str.compare("nan") ||
        !str.compare("nanf") ||
        !str.compare("+inf") ||
        !str.compare("+inff") ||
        !str.compare("-inf") ||
        !str.compare("-inff"))
        return true;
    return false;
}

void ScalarConverter::convertFromChar(std::string str)
{
	_charValue = str[0];
	_tmpInt = static_cast<int>(_charValue);
	_floatValue = static_cast<float>(_charValue);
	_doubleValue = static_cast<double>(_charValue);

	displayResult();
}

void ScalarConverter::convertFromInt(std::string str)
{
  	std::istringstream iss(str);
    iss >> _tmpInt;

    if (iss.fail())
	{
        displayResult();
		
    }
	else 
	{
        _charValue = static_cast<char>(_tmpInt);
        _floatValue = static_cast<float>(_tmpInt);
        _doubleValue = static_cast<double>(_tmpInt);

        displayResult();
    }

	
}

void ScalarConverter::convertFromFloat(std::string str)
{
    std::istringstream iss(str);
    iss >> _floatValue;

    if (iss.fail()) 
	{
        std::cout << "failfloat" << std::endl;
    } 
	else 
	{
        _charValue = static_cast<char>(_floatValue);
        _tmpInt = static_cast<int>(_floatValue);
        _doubleValue = static_cast<double>(_floatValue);

        displayResult();
    }
}

void ScalarConverter::convertFromDouble(std::string str)
{
    std::istringstream iss(str);
    iss >> _doubleValue;

    if (iss.fail()) 
	{
        std::cout << "faildoub" << std::endl;
    } 
	else 
	{
        _charValue = static_cast<char>(_doubleValue);
        _tmpInt = static_cast<int>(_doubleValue);
        _floatValue = static_cast<float>(_doubleValue);

        displayResult();
    }
}

void ScalarConverter::displayResult()
{
    std::cout << "char: ";
	try
	{
		if (!isprint(_charValue) || !isascii(_charValue))
			std::cerr << "Non displayable" << std::endl;
		else
			std::cout << "'" << _charValue << "'" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "impossible" << std::endl;
	}


	std::cout << "int: ";
	try
	{
		if (_floatValue < INT_MIN || _doubleValue < INT_MIN ||  _floatValue > INT_MAX ||  _doubleValue > INT_MAX)
			std::cerr << "impossible" << std::endl;
		else
			std::cout << _tmpInt << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "impossible" << std::endl;
	}
	

	std::cout << "float: ";
	try
	{
		if (precisionCount > 0)
			std::cout << std::setprecision(precisionCount) << std::fixed << _floatValue  << "f" << std::endl;
		else
			std::cout << std::setprecision(precisionCount) << std::fixed << _floatValue  << ".0f" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "impossible" << std::endl;
	}
	

	std::cout << "double: ";
	try
	{
		if (precisionCount > 0)
			std::cout << std::setprecision(precisionCount) << std::fixed << _doubleValue << std::endl;
		else
			std::cout << std::setprecision(precisionCount) << std::fixed << _doubleValue << ".0" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "impossible" << std::endl;
	}
}