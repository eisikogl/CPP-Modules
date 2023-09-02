#pragma once
#include <exception>

template <typename T>
class Array
{
    private:
        T *_data;
        unsigned int _size;

    public:
        Array();
        Array(const Array &copy);
        Array &operator = (const Array &assign);
        ~Array();

        Array(unsigned int size);
        T &operator [] (unsigned int index);
        unsigned int size() const;
};

#include "Array.tpp"