#include "RPN.hpp"
#include "iostream"

RPN::RPN(){}
RPN::~RPN(){}

void RPN::polish(const std::string &str)
{
    for(size_t i = 0; i < str.size();i++)
    {
        if(isdigit(str[i]))
        {
            int value = str[i] - '0';
            data.push(value);
        }
        if(data.size() > 2)
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
    std::cout << data.top() << std::endl;
}