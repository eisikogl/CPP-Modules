#include "Span.hpp"

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

void Span::shortestSpan()
{
    if(max_value <= 1)
        throw std::runtime_error("Too few Numbers in the Container to use this operation");
    
}

void Span::longestSpan()
{
    if(max_value <= 1)
        throw std::runtime_error("Too few Numbers in the Container to use this operation");
    
}