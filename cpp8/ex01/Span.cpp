#include "Span.hpp"
#include <limits>

Span::Span(unsigned int max) : max_value(max)
{

}

Span::~Span()
{

}

Span::Span(const Span &copy) : max_value(copy.max_value)
{

}

Span &Span::operator = (const Span &assign)
{
	if(this != &assign)
    {
        max_value = assign.max_value;
    }
    return *this;
}

void Span::addNumber(int value)
{
    if(data.size() >= max_value)
    {
        throw std::runtime_error("Cant hold more Integers, im full");
    }
    data.push_back(value);
    std::cout << "Added new Value: " << value << std::endl; 
}

int Span::shortestSpan()
{
    if(max_value <= 1)
        throw std::runtime_error("Too few Numbers in the Container to use this operation");
   // std::vector<int>::iterator findSpan = data.begin();

    int shortestSpan = std::numeric_limits<int>::max();
    int Span;
    for (size_t i = 0; i < data.size() - 1;++i)
    {
        for (size_t j = i + 1; j < data.size();++j)
        {
            if(data[i] > data[j])
                Span = data[i] - data[j];
            else
                Span = data[j] - data[i];
            shortestSpan = std::min(Span,shortestSpan);
        }
    }
    return shortestSpan;
}

int Span::longestSpan()
{
    if(max_value <= 1)
        throw std::runtime_error("Too few Numbers in the Container to use this operation");
    std::vector<int>::iterator min = std::min_element(data.begin(), data.end());
    std::vector<int>::iterator max = std::max_element(data.begin(), data.end());
    int minValue = *min;
    int maxValue = *max;

    return maxValue - minValue;
}
