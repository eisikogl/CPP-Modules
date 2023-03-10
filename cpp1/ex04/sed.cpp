#include "sed.hpp"

sed::sed(char *filename)
{
    std::ifstream inFile(filename);
	std::string ret = "";
	std::string tmp;

	while( getline(inFile, tmp) )
	{
		ret += tmp + "\n";
	}
	_text = ret;
	_filename = filename;
}

sed::~sed()
{
    _filename += ".replace";
	std::cout << _filename << " is created." << std::endl;
	std::ofstream outfile(_filename);
	outfile << _text;
	outfile.close();
}

void sed::replace(char *src,char *dest)
{
    std::string newString = "";
	const char *str = _text.c_str();
	int i = 0;

	int	j, k;
	while (str[i])
	{
		j = 0;
		k = 0;
		while(str[i + j] == src[k])
		{
			j++;
			k++;
			if (!src[k])
			{
				i += j;
				newString += dest;
			}
		}
		newString += str[i++];
	}
	_text = newString;
    
}