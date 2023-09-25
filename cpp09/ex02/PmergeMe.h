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

	template <typename CONTAINER>
	void merge(CONTAINER &vector, int vectorLength, CONTAINER leftVector, CONTAINER rightVector) {
		int leftLength = vectorLength / 2;
		int rightLength = vectorLength - leftLength;
		int i = 0, l = 0, r = 0;

		while (l < leftLength && r < rightLength) {
			if (leftVector[l] < rightVector[r])
				vector[i] = leftVector[l++];
			else
				vector[i] = rightVector[r++];
			i++;
		}
		while (l < leftLength)
			vector[i++] = leftVector[l++];
		while (r < rightLength)
			vector[i++] = rightVector[r++];
	}

	template <typename CONTAINER>
	void mergeSort(CONTAINER &container) {
		CONTAINER leftVector;
		CONTAINER rightVector;

		int vectorLength = container.size();
		int mid = vectorLength / 2;
		if (vectorLength <= 1)
			return;
		for (int i = 0; i < vectorLength; i++) {
			if (i >= mid)
				rightVector.push_back(container[i]);
			else
				leftVector.push_back(container[i]);
		}
		mergeSort(leftVector);
		mergeSort(rightVector);
		merge(container, vectorLength, leftVector, rightVector);
	}

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
