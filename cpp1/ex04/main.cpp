#include "FileManager.hpp"

int main(int argc, char *argv[])
{
    if (!(argc == 4))
    {
        std::cout << "Invalid argument count!" << std::endl;
        return 0;
    }
    
    FileManager fileManager;

    fileManager.setFileName(argv[1]);
    fileManager.setFromStr(argv[2]);
    fileManager.setToStr(argv[3]);

    if (!fileManager.replaceStrings())
        std::cout << "Error!" << std::endl;
    return 0;
}