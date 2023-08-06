// main.cpp
#include "Array.hpp"
#include <iostream>

int main() {
    try {
        Array<int> arr1(5);
        for (size_t i = 0; i < arr1.size(); ++i) {
            arr1[i] = i * 10;
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;

        Array<int> arr2 = arr1;
        arr2[2] = 999;
        std::cout << "arr1[2]: " << arr1[2] << std::endl;  // Should print 20
        std::cout << "arr2[2]: " << arr2[2] << std::endl;  // Should print 999

        // This should throw an exception
        std::cout << arr1[10] << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
