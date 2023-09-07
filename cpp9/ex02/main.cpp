#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    std::list<int> dataList;
    std::deque<int> dataDeque;    for (int i = 1; i < argc; ++i) 
    {
        int value = atoi(argv[i]);
        dataList.push_back(value);
        dataDeque.push_back(value);
    }    PmergeMe sorter(dataList, dataDeque);    struct timeval startList, endList, startDeque, endDeque;    // Measure sorting time for list
    gettimeofday(&startList, NULL);
    sorter.sortUsingList();
    gettimeofday(&endList, NULL);
    long durationListMicros = (endList.tv_sec - startList.tv_sec) * 1e6 + (endList.tv_usec - startList.tv_usec);    // Measure sorting time for deque
    gettimeofday(&startDeque, NULL);
    sorter.sortUsingDeque();
    gettimeofday(&endDeque, NULL);
    long durationDequeMicros = (endDeque.tv_sec - startDeque.tv_sec) * 1e6 + (endDeque.tv_usec - startDeque.tv_usec);    // Display the results
    std::cout << "Time taken using list: " << durationListMicros << " microseconds" << std::endl;
    std::cout << "Time taken using deque: " << durationDequeMicros << " microseconds" << std::endl;    return 0;
}