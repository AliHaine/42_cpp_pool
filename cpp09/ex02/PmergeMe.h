#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <vector>
#include <deque>
#include <chrono>


class PmergeMe {
public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &pmergeMe);
    PmergeMe &operator=(const PmergeMe &pmergeMe);
    ~PmergeMe(void);

	void insertionSortVector(std::vector<unsigned int> &vector);
	void mergeVector(std::vector<unsigned int> &vector, int vectorLength, std::vector<unsigned int> leftVector, std::vector<unsigned int> rightVector);
	void sortVector(std::vector<unsigned int> &vector);

	void insertionSortDeque(std::deque<unsigned int> &deque);
	void mergeDeque(std::deque<unsigned int> &deque, int dequeLength, std::deque<unsigned int> leftDeque, std::deque<unsigned int> rightDeque);
	void sortDeque(std::deque<unsigned int> &deque);

	template <typename CONTAINER_ITERATOR>
	void displayContainer(CONTAINER_ITERATOR containerStart, CONTAINER_ITERATOR containerEnd) {
		while (containerStart != containerEnd) {
			std::cout << *containerStart << " ";
			containerStart++;
		}
		std::cout << std::endl;
	}
};

#endif
