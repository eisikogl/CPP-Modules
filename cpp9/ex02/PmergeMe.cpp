#include "PmergeMe.hpp"
#include <cstdlib>
#include <exception>
#include <climits>

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy):dataDeque_(copy.dataDeque_),dataList_(copy.dataList_){}

PmergeMe& PmergeMe::operator=(const PmergeMe &copy)
{
    if(this != &copy)
    {
        dataDeque_ = copy.dataDeque_;
        dataList_ = copy.dataList_;
    }
}

void PmergeMe::sortUsingList() 
{
    if (dataList_.empty()) return;

    std::list<int>::iterator it1, it2;

    for (it1 = dataList_.begin(); it1 != dataList_.end(); ++it1) 
    {
        int value = *it1;
        it2 = it1;
        --it2;

        while (it2 != dataList_.begin() && *it2 > value)
        {
            std::list<int>::iterator temp = it2;
            ++temp;
            *temp = *it2;
            --it2;
        }

        std::list<int>::iterator temp = it2;
        ++temp;
        if (*it2 > value) 
        {
            *temp = *it2;
            *it2 = value;
        } 
        else 
        {
            *temp = value;
        }
    }
}


void PmergeMe::sortUsingDeque() 
{
    if (dataDeque_.empty()) return;

    std::deque<int>::iterator it1, it2;

    for (it1 = dataDeque_.begin() + 1; it1 != dataDeque_.end(); ++it1) 
    {
        int value = *it1;
        it2 = it1;
        --it2;

        while (it2 >= dataDeque_.begin() && *it2 > value) 
        {
            *(it2 + 1) = *it2;
            if (it2 != dataDeque_.begin()) 
            {
                --it2;
            }
            else
            {
                break;
            }
        }

        if (it2 >= dataDeque_.begin() && *it2 > value) 
        {
            *(it2 + 1) = *it2;
            *it2 = value;
        } 
        else 
        {
            *(it2 + 1) = value;
        }
    }
}

std::list<int> PmergeMe::getListData() const 
{
    return dataList_;
}

std::deque<int> PmergeMe::getDequeData() const 
{
    return dataDeque_;
}

int PmergeMe::listsize()
{
    return dataList_.size();
}

int PmergeMe::dequesize()
{
    return dataDeque_.size();
}

void PmergeMe::printdataDeque()
{
    if(!dataDeque_.empty())
    {
        std::deque<int>::iterator it;
        for(it = dataDeque_.begin();it != dataDeque_.end();it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "empty container" << std::endl;
    }
}

void PmergeMe::printdataList()
{
    if(!dataList_.empty())
    {
        std::list<int>::iterator it = dataList_.begin();
        for(;it != dataList_.end();it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "empty container" << std::endl;
    }
}

void PmergeMe::parser(int argc,char *argv[])
{
    if(argc < 2)
        throw std::exception();
    for (int i = 1; i < argc; ++i) 
    {
        char* endptr;
        long value = strtol(argv[i], &endptr, 10);

        if (*endptr != '\0' || value < 0 || value > INT_MAX)
            throw std::exception();

        dataList_.push_back(static_cast<int>(value));
        dataDeque_.push_back(static_cast<int>(value));
    }

}