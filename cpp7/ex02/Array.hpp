// Array.hpp
#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* _data;
    size_t _size;

public:
    // Default constructor
    Array() : _data(nullptr), _size(0) {}

    // Parameterized constructor
    Array(size_t n) : _data(new T[n]()), _size(n) {}

    // Copy constructor
    Array(const Array& other) : _data(new T[other._size]), _size(other._size) {
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;

            _data = new T[other._size];
            _size = other._size;

            for (size_t i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Array() {
        delete[] _data;
    }

    // Subscript operator
    T& operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return _data[index];
    }

    // Const version of subscript operator
    const T& operator[](size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Array index out of bounds");
        }
        return _data[index];
    }

    // size() function
    size_t size() const {
        return _size;
    }
};
