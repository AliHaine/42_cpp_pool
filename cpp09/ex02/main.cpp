#include "PmergeMe.h"

static void merge(std::vector<unsigned int> &vector, int vectorLength,std::vector<unsigned int> leftVector, std::vector<unsigned int> rightVector) {
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

static void mergeSort(std::vector<unsigned int> &vector) {
	std::vector<unsigned int> leftVector;
	std::vector<unsigned int> rightVector;

	int vectorLength = vector.size();
	int mid = vectorLength / 2;
	if (vectorLength <= 1)
		return;
	for (int i = 0; i < vectorLength; i++) {
		if (i >= mid)
			rightVector.push_back(vector[i]);
		else
			leftVector.push_back(vector[i]);
	}
	mergeSort(leftVector);
	mergeSort(rightVector);
	merge(vector, vectorLength, leftVector, rightVector);
}

int main(int argc, char *argv[]) {
	std::chrono::time_point<std::chrono::system_clock> start, end;
    std::vector<unsigned int> vector;

    for (int i = 1; i < argc; i++) {
        int val = atoi(argv[i]);
        if (val <= 0) {
            std::cout << "Error" << std::endl;
            return 1;
        }
        vector.push_back(val);
    }
		std::cout << std::clock() << std::endl;


	std::cout << "Before:	";
	for (std::vector<unsigned int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	start = std::chrono::system_clock::now();
	mergeSort(vector);
	end = std::chrono::system_clock::now();

	std::cout << "After:	";
	for (std::vector<unsigned int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;


    return 1;
}