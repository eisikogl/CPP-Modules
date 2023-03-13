#include "FileManager.hpp"

FileManager::FileManager()
{
    this->fileName.clear();
    this->fromStr.clear();
    this->toStr.clear();
}

FileManager::~FileManager()
{
    this->fileName.clear();
    this->fromStr.clear();
    this->toStr.clear();
}

void FileManager::setFileName(std::string _fileName)
{
    this->fileName = _fileName;
}

void FileManager::setFromStr(std::string _fromStr)
{
    this->fromStr = _fromStr;
}

void FileManager::setToStr(std::string _toStr)
{
    this->toStr = _toStr;
}

std::string FileManager::getFileName() const
{
    return this->fileName;
}

std::string FileManager::getFromStr() const
{
    return this->fromStr;
}

std::string FileManager::getToStr() const
{
    return this->toStr;
}

bool FileManager::replaceStrings()
{
    std::string line;
    std::string output;

    std::ifstream inputFile(getFileName());
    if (!inputFile.is_open())
    {
        std::cout << "Could not open this file: " << getFileName() << std::endl;
        return false;
    }

    std::ofstream outputFile(getFileName().append(".replace"));
    if (!outputFile.is_open())
    {
        std::cout << "Could not open this file: " << getFileName().append(".replace") << std::endl;
        return false;
    }

    while (std::getline(inputFile, line))
    {
        for (size_t i = 0; 1; i+= getToStr().length())
        {
            i = line.find(getFromStr(), i);
            if (i == std::string::npos)
                break;
            line.erase(i, getFromStr().length());
            line.insert(i, getToStr());
        }
        output.append(line);
        if (!inputFile.eof())
            output.append("\n");
    }
    outputFile << output;
    inputFile.close();
    outputFile.close();
    return true;
}