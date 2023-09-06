#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    std::list<int> dataList;
    std::deque<int> dataDeque;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        dataList.push_back(value);
        dataDeque.push_back(value);
    }

    PmergeMe sorter(dataList, dataDeque);


    struct timeval startList, endList;
    gettimeofday(&startList, NULL);
    sorter.sortUsingList();
    gettimeofday(&endList, NULL);
    double durationList = (endList.tv_sec - startList.tv_sec) + (endList.tv_usec - startList.tv_usec) * 1e-6;

    struct timeval startDeque, endDeque;
    gettimeofday(&startDeque, NULL);
    sorter.sortUsingDeque();
    gettimeofday(&endDeque, NULL);
    double durationDeque = (endDeque.tv_sec - startDeque.tv_sec) + (endDeque.tv_usec - startDeque.tv_usec) * 1e-6;

    std::cout << "Time taken using list: " << durationList << " seconds" << std::endl;
    std::cout << "Time taken using deque: " << durationDeque << " seconds" << std::endl;

    return 0;
}
