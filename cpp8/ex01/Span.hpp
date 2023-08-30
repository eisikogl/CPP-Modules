#include <iostream>
#include <vector>
#include <stdexcept>

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
    void shortestSpan();
    void longestSpan();
};

