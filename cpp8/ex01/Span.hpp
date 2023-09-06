#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
private:
    std::vector<int> data;
    unsigned int max_value;
public:
    Span();
    ~Span();
    Span(unsigned int max);
    Span(const Span &copy);
    Span &operator = (const Span &assign);

    void addNumber(int value);
    void addNumber(const std::vector<int>& values);
    int shortestSpan();
    int longestSpan();
};

