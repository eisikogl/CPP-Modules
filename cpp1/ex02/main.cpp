#include <string>
#include <iostream>

int main()
{
    std::string myString = "HI THIS IS BRAIN";
    std::string *stringPTR = &myString;
    std::string &stringREF = myString;
    
    std::cout.width(50);
    std::cout << std::left << "memory address of the string variable: " << std::right << &myString << std::endl;
    std::cout.width(50);
    std::cout << std::left << "memory adress held by stringPTR: " << std::right << stringPTR << std::endl;
    std::cout.width(50);
    std::cout << std::left << "memory adress held by stringREF: " << std::right << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout.width(50);
    std::cout << std::left << "The value of the string variable: " << std::right << myString << std::endl;
    std::cout.width(50);
    std::cout << std::left << "The value pointed to by stringPTR: " << std::right << *stringPTR << std::endl;
    std::cout.width(50);
    std::cout << std::left << "The value pointed to by stringREF: " << std::right << stringREF << std::endl; 
}