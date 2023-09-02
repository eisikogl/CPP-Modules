#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    _size = 0;
    _data = NULL;
}

template <typename T>
Array<T>::Array(const Array &copy)
{
    _size = copy._size;
    _data = new T[_size];
    for(unsigned int i = 0;i < _size; i++)
        _data[i] = copy._data[i];
}

template <typename T>
Array<T> &Array<T>::operator =(const Array &copy)
{
    if(this != &copy)
    {
        delete[] _data;
        _size = copy.size;
        _data = new T[_size]();
        for (unsigned int i = 0;i < _size;i++)
            _data[i] = copy.data[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    if (_data != NULL)
        delete[] _data;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
    _data = new T[n]();
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if(index >= _size)
        throw std::exception();
    return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}