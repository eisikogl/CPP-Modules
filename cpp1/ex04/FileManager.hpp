#ifndef __FILEMANAGER_HPP__
#define __FILEMANAGER_HPP__

#include <iostream>
#include <fstream>

class FileManager
{
    private:
        std::string fileName;
        std::string fromStr;
        std::string toStr;
    public:
        FileManager();
        ~FileManager();

        void setFileName(std::string _fileName);
        void setFromStr(std::string _fromStr);
        void setToStr(std::string _toStr);

        std::string getFileName() const;
        std::string getFromStr() const;
        std::string getToStr() const;

        bool replaceStrings();
};


#endif