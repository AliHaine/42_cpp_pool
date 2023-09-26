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

void PmergeMe::insertionSortVector(std::vector<unsigned int> &vector) {
	int temp;
	std::vector<unsigned int>::iterator tempIterator;

	for (std::vector<unsigned int>::iterator it = vector.begin() + 1; it != vector.end(); it++) {
		tempIterator = it;
		while (*tempIterator < *(tempIterator - 1) && tempIterator != vector.begin()) {
			temp = *tempIterator;
			*tempIterator = *(tempIterator - 1);
			*(tempIterator - 1) = temp;
			tempIterator--;
		}
	}
}

void PmergeMe::mergeVector(std::vector<unsigned int> &vector, int vectorLength, std::vector<unsigned int> leftVector, std::vector<unsigned int> rightVector) {
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

void PmergeMe::sortVector(std::vector<unsigned int> &vector) {
	std::vector<unsigned int> leftVector;
	std::vector<unsigned int> rightVector;

	int vectorLength = vector.size();
	int mid = vectorLength / 2;
	if (vectorLength <= 5) {
		insertionSortVector(vector);
		return;
	}
	for (int i = 0; i < vectorLength; i++) {
		if (i >= mid)
			rightVector.push_back(vector[i]);
		else
			leftVector.push_back(vector[i]);
	}
	sortVector(leftVector);
	sortVector(rightVector);
	mergeVector(vector, vectorLength, leftVector, rightVector);
}

void PmergeMe::insertionSortDeque(std::deque<unsigned int> &deque) {
	int temp;
	std::deque<unsigned int>::iterator tempIterator;

	for (std::deque<unsigned int>::iterator it = deque.begin() + 1; it != deque.end(); it++) {
		tempIterator = it;
		while (*tempIterator < *(tempIterator - 1) && tempIterator != deque.begin()) {
			temp = *tempIterator;
			*tempIterator = *(tempIterator - 1);
			*(tempIterator - 1) = temp;
			tempIterator--;
		}
	}
}

void PmergeMe::mergeDeque(std::deque<unsigned int> &deque, int dequeLength, std::deque<unsigned int> leftDeque, std::deque<unsigned int> rightDeque) {
	int leftLength = dequeLength / 2;
	int rightLength = dequeLength - leftLength;
	int i = 0, l = 0, r = 0;

	while (l < leftLength && r < rightLength) {
		if (leftDeque[l] < rightDeque[r])
			deque[i] = leftDeque[l++];
		else
			deque[i] = rightDeque[r++];
		i++;
	}
	while (l < leftLength)
		deque[i++] = leftDeque[l++];
	while (r < rightLength)
		deque[i++] = rightDeque[r++];
}

void PmergeMe::sortDeque(std::deque<unsigned int> &deque) {
	std::deque<unsigned int> leftDeque;
	std::deque<unsigned int> rightDeque;

	int dequeLength = deque.size();
	int mid = dequeLength / 2;
	if (dequeLength <= 5) {
		insertionSortDeque(deque);
		return;
	}
	for (int i = 0; i < dequeLength; i++) {
		if (i >= mid)
			rightDeque.push_back(deque[i]);
		else
			leftDeque.push_back(deque[i]);
	}
	sortDeque(leftDeque);
	sortDeque(rightDeque);
	mergeDeque(deque, dequeLength, leftDeque, rightDeque);
}