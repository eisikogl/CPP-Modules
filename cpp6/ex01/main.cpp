#include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

int main()
{
    Data *products = new Data();
    products->name = "umbrella";
    products->price = 50;
    products->amount = 1000;


    std::cout << "----Product DATABASE----" << std::endl;
    std::cout << "Product Name: " << products->name << std::endl;
    std::cout << "Product Price: " << products->price << std::endl;
    std::cout << "Product Amount: " << products->amount << std::endl;

    Data *productsDatabase = deserialize(serialize(products));
    std::cout << "----Product DATABASE After SerDes----" << std::endl;
    std::cout << "Product Name: " << productsDatabase->name << std::endl;
    std::cout << "Product Price: " << productsDatabase->price << std::endl;
    std::cout << "Product Amount: " << productsDatabase->amount << std::endl;
    return 0;
}
