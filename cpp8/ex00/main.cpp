#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
	vec.push_back(100);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
    try
    {
        std::cout << easyfind(vec,30) << std::endl;
    }
    catch (std::exception &a)
    {
		std::cout << a.what() <<std::endl;
	}
}