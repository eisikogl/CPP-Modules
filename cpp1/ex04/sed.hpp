#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>
#include <fstream>

class sed
{
private:
    std::string _text;
	std::string _filename;
public:
    sed(char *);
    ~sed();
    void replace(char *,char *);
};



#endif