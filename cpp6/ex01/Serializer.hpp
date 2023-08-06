#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

struct Data {
    int a;
    float b;
};

class Serializer {
public:
    Serializer();
    Serializer(const Serializer &copy);
    Serializer& operator=(const Serializer &assign);
    ~Serializer();

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif