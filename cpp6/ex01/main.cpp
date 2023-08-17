#include "Serializer.hpp"

int main()
{
    Data originalData;
    originalData.a = 42;
    originalData.b = 3.14f;
    uintptr_t serializedPtr;
    Data* deserializedPtr;
    
    Data originalData;
    uintptr_t serializedPtr;
    Data* deserializedPtr;

    serializedPtr = Serializer::serialize(&originalData);
    deserializedPtr = Serializer::deserialize(serializedPtr);

    std::cout << "im the original Pointer: " << &originalData << std::endl;
    std::cout << "im serialized: " << serializedPtr << std::endl;
    std::cout << "im deserilized: " << deserializedPtr << std::endl;

    return 0;
}
