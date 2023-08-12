#include "Serializer.hpp"

int main()
{
    Data originalData;
    originalData.a = 42;
    originalData.b = 3.14f;
    uintptr_t serializedPtr;
    Data* deserializedPtr;

    std::cout << "Created Data object at address: " << &originalData << std::endl;

    serializedPtr = Serializer::serialize(&originalData);

    std::cout << "Serialized Data pointer value: " << serializedPtr << std::endl;

    deserializedPtr = Serializer::deserialize(serializedPtr);

    std::cout << "Deserialized Data pointer at address: " << deserializedPtr << std::endl;

    if (deserializedPtr == &originalData)
    {
        std::cout << "Deserialization successful. Pointers match." << std::endl;
        std::cout << "Original Data: a = " << originalData.a << ", b = " << originalData.b << std::endl;
    }
    else
    {
        std::cout << "Deserialization failed. Pointers do not match." << std::endl;
    }

    return 0;
}
