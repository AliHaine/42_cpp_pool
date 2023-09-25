#include "PmergeMe.h"

PmergeMe::PmergeMe(void) {
    std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe) {
    (void)pmergeMe;
    std::cout << "PmergeMe copy constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe) {
    (void)pmergeMe;
    std::cout << "PmergeMe copy assign constructor called" << std::endl;
    return (*this);
}

PmergeMe::~PmergeMe(void) {
    std::cout << "PmergeMe destrcutor called" << std::endl;
}