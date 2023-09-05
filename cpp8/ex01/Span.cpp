#include "Span.hpp"
#include <vector>
#include <algorithm>
#include <numeric>

Span::Span(unsigned int max) : max_value(max)
{

}

Span::~Span()
{

}

Span::Span(const Span &copy) : max_value(copy.max_value) , data(copy.data)
{

}

Span &Span::operator = (const Span &assign)
{
	if(this != &assign)
    {
        if(!data.empty())
        {
             for(unsigned int i = 0; i < data.size(); i++)
                data[i] = assign.data[i];
        }
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
    if(data.size() <= 1)
        throw std::runtime_error("Too few Numbers in the Container to use this operation");

    std::sort(data.begin(), data.end());
    std::vector<int> differences(data.size() - 1);
    std::adjacent_difference(data.begin(), data.end(), differences.begin());

    return *std::min_element(differences.begin() + 1, differences.end());
}

int Span::longestSpan()
{
    if(max_value <= 1)
        throw std::runtime_error("Too few Numbers in the Container to use this operation");
    int minValue;
    int maxValue;
    minValue = *std::min_element(data.begin(), data.end());
    maxValue = *std::max_element(data.begin(), data.end());

    return maxValue - minValue;
}
