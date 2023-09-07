#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::list<int>& dataList, const std::deque<int>& dataDeque)
    : dataList_(dataList), dataDeque_(dataDeque) 
{
}

PmergeMe::~PmergeMe() 
{

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
