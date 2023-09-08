#include "PmergeMe.hpp"
#include <cstdlib>
#include <exception>
#include <climits>

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy):dataList_(copy.dataList_),dataDeque_(copy.dataDeque_){}

PmergeMe& PmergeMe::operator=(const PmergeMe &copy)
{
    if(this != &copy)
    {
        dataList_ = copy.dataList_;
        dataDeque_ = copy.dataDeque_;
    }
    return *this;
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

void PmergeMe::sortUsingDeque()
{
    merge_sort(dataDeque_);
}

void PmergeMe::sortUsingList()
{
    merge_sort(dataList_);
}

void merge(std::deque<int>& arr, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::deque<int> L(n1), R(n2);
	for (i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) 
    {
		if (L[i] <= R[j]) 
        {
			arr[k] = L[i];
			i++;
		}
		else 
        {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) 
    {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) 
    {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(std::deque<int>& arr, int left, int right)
{
	if (left < right) 
    {
		int mid = left + (right - left) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void merge_sort(std::deque<int>& arr)
{
	merge_sort(arr, 0, arr.size() - 1);
}

void merge(std::list<int>& arr, std::list<int>& left, std::list<int>& right)
{
	std::list<int>::iterator i = left.begin();
	std::list<int>::iterator j = right.begin();

	while (i != left.end() && j != right.end()) 
    {
		if (*i < *j) {
			arr.push_back(*i);
			i++;
		}
		else {
			arr.push_back(*j);
			j++;
		}
	}

	while (i != left.end()) 
    {
		arr.push_back(*i);
		i++;
	}

	while (j != right.end()) 
    {
		arr.push_back(*j);
		j++;
	}
}

void merge_sort(std::list<int>& arr)
{
	if (arr.size() < 2) 
    {
		return;
	}

	std::list<int> left, right;
	std::list<int>::iterator it = arr.begin();
	int count = 0;
	while (it != arr.end()) 
    {
		if (count < (int)arr.size() / 2) 
        {
			left.push_back(*it);
		}
		else 
        {
			right.push_back(*it);
		}
		count++;
		it++;
	}

	merge_sort(left);
	merge_sort(right);

	arr.clear();
	merge(arr, left, right);
}