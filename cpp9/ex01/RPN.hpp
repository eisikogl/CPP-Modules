#pragma once

#include <vector>
#include <stack>
#include <string>
class RPN
{
private:
    std::stack<int, std::vector<int> > data;
public:
    RPN();
    ~RPN();
    RPN(const RPN &copy);
    RPN &operator=(const RPN &copy);

    void polish(const std::string &str);
};

bool checkinput(const std::string &str);