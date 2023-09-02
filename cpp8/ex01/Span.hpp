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
    Span(unsigned int max);
    ~Span();
    Span(const Span &copy);
    Span &operator = (const Span &assign);

    void addNumber(int value);
    int shortestSpan();
    int longestSpan();
};

