#include "Converter.hpp"

int main(int argc, char const *argv[])
{
    if (argc < 2 || !*argv)
    {
        std::cerr << "Invalid argument count!" << std::endl;
        return 1;
    }

    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "" << std::endl;
    }
    
    return 0;
}
