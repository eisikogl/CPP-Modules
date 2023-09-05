#pragma once
#include <list>
#include <deque>

class PmergeMe
{
private:
    std::list<int> myListcont;
    std::deque<int> myDequecont;

    void FordJohnsonSortDeque();
    void FordJohnsonSortList();
public:
    PmergeMe();
    ~PmergeMe();

    void sort();                          // Main function to sort using Ford-Johnson algorithm
    std::deque<int> getSortedDeque() const; // Returns the sorted sequence from deque
    std::list<int> getSortedList() const;   // Returns the sorted sequence from list

    double getTimeDeque() const;           // Returns the time taken for sorting using deque
    double getTimeList() const;            // Returns the time taken for sorting using list
};
