#include "RPN.hpp"
#include "iostream"
#include <algorithm>
#include <cctype>

//maybe handle double digits and negative numbers

RPN::RPN(){}
RPN::~RPN(){}

RPN::RPN(const RPN &copy) : data(copy.data){}

RPN &RPN::operator=(const RPN &copy)
{
    if(this != &copy)
        data = copy.data;
    return *this;
}

bool checkinput(const std::string &str)
{
    if(str.empty())
    {
        std::cout << "Error: empty string"<< std::endl;
            return false;
    }
    if(str.size() <= 2)
    {
        std::cout << "Error: string too small"<< std::endl;
            return false;
    }
    int operant = 0;
    int digit = 0;
    for(size_t i = 0; i < str.size();i++)
    {
        if(std::string("+-/*").find(str[i]) != std::string::npos)
            operant++;
        if (std::isdigit(str[i]))
            digit++;
    }
    if(digit != operant + 1)
    {
        std::cout << "Error: invalid, either insufficent or excessive operants"<< std::endl;
        return false;
    }

    for(size_t i = 0; i < str.size();i++)
    {
        if (std::string("+-/* ").find(str[i]) == std::string::npos && !(std::isdigit(str[i])))
        {
            std::cout << "Error"<< std::endl;
            return false;
        }
    }
    return true;
}
void RPN::polish(const std::string &str)
{
    for(size_t i = 0; i < str.size();i++)
    {
        if(std::isdigit(str[i]))
        {
            int value = str[i] - '0';
            data.push(value);
        }
        if(data.size() >= 2)
        {
            if(str[i] == '+')
            {
                int a = data.top(); data.pop();
                int b = data.top(); data.pop();

                int c = b + a;
                data.push(c);
            }
            if(str[i] == '-')
            {
                int a = data.top(); data.pop();
                int b = data.top(); data.pop();

                int c = b - a;
                data.push(c);
            }
            if(str[i] == '/')
            {
                int a = data.top(); data.pop();
                int b = data.top(); data.pop();
                if(a == 0)
                {
                    std::cout << "Error: cant devide by 0" << std::endl;
                    while(!data.empty())
                        data.pop();
                    break;
                }
                int c = b / a;
                data.push(c);
            }
            if(str[i] == '*')
            {
                int a = data.top(); data.pop();
                int b = data.top(); data.pop();

                int c = b * a;
                data.push(c);
            }
        }
    }
    if(!data.empty())
        std::cout << data.top() << std::endl;
}
