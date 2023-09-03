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

    void polish(const std::string &str);

};