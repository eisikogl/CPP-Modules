#include <iostream>
#include <sys/time.h>
#include "PmergeMe.hpp"

// #include <ctime>
// std::clock_t start = std::clock();
// operation
// std::clock_t end = std::clock();
// double elapsed = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
// return elapsed;

int main(int argc, char* argv[]) 
{
    PmergeMe sorter;
    try
    {
        sorter.parser(argc,argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::cout << "Before: "; 
    sorter.printdataDeque();
    struct timeval startList, endList, startDeque, endDeque;
    gettimeofday(&startList, NULL);
    sorter.sortUsingList();
    gettimeofday(&endList, NULL);
    long durationListMicros = (endList.tv_sec - startList.tv_sec) * 1e6 + (endList.tv_usec - startList.tv_usec);
    gettimeofday(&startDeque, NULL);
    sorter.sortUsingDeque();
    gettimeofday(&endDeque, NULL);
    long durationDequeMicros = (endDeque.tv_sec - startDeque.tv_sec) * 1e6 + (endDeque.tv_usec - startDeque.tv_usec);
    std::cout << "After: ";
    sorter.printdataDeque();
    sorter.printdataList();
    
    //sorter.printdataList();
    std::cout << "Time to process a range of " << sorter.listsize() << " elements with std::list : " << durationListMicros << " microseconds" << std::endl;
    std::cout << "Time to process a range of " << sorter.listsize() << " elements with std::deque : " << durationDequeMicros << " microseconds" << std::endl;
}