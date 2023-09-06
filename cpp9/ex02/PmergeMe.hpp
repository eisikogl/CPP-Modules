#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <deque>

class PmergeMe {
public:
    PmergeMe(const std::list<int>& dataList, const std::deque<int>& dataDeque);
    ~PmergeMe();

    void sortUsingList();
    void sortUsingDeque();

    std::list<int> getListData() const;
    std::deque<int> getDequeData() const;

private:
    std::list<int> dataList_;
    std::deque<int> dataDeque_;

};

#endif
