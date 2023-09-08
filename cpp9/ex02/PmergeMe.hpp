#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <deque>

class PmergeMe {
private:
    std::list<int> dataList_;
    std::deque<int> dataDeque_;
public:
    PmergeMe();
    ~PmergeMe();
    //PmergeMe(const PmergeMe &copy);

    void sortUsingList();
    void sortUsingDeque();

    int listsize();
    int dequesize();
    std::list<int> getListData() const;
    std::deque<int> getDequeData() const;
    void printdataList();
    void printdataDeque();
    void parser(int arg,char *argv[]);

};

#endif
