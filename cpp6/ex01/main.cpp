#include "Serializer.hpp"

int main() {
    Data data = {10, 20.5f};
    Data* ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);
    Data* deserialized = Serializer::deserialize(raw);

    if (ptr == deserialized) 
    {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    } 
    else 
    {
        std::cout << "Something went wrong!" << std::endl;
    }

    return 0;
}
