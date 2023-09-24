#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <vector>
#include <chrono>

class PmergeMe {
public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &pmergeMe);
    PmergeMe &operator=(const PmergeMe &pmergeMe);
    ~PmergeMe(void);
};

#endif
