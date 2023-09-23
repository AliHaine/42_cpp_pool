#include "PmergeMe.h"

PmergeMe::PmergeMe(void) {
    std::cout << "42 norm.." << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe) {
    (void)pmergeMe;
    std::cout << "42 norm.." << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe) {
    (void)pmergeMe;
    std::cout << "42 norm.." << std::endl;
    return (*this);
}

PmergeMe::~PmergeMe(void) {
    std::cout << "42 norm.." << std::endl;
}