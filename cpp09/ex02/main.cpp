#include "PmergeMe.h"

int main(int argc, char *argv[]) {
	clock_t start, end;
	std::vector<unsigned int> vector;
    std::deque<unsigned int> deque;
	PmergeMe pe;

	if (argc <= 1)
		return 2;
    for (int i = 1; i < argc; i++) {
        int val = atoi(argv[i]);
        if (val <= 0) {
            std::cout << "Error" << std::endl;
            return 1;
        }
        vector.push_back(val);
		deque.push_back(val);
    }

	std::cout << "Before:	";
	pe.displayContainer(vector.begin(), vector.end());

	start = clock();
	pe.mergeSort(vector);
	end = clock();
	double time_taken1 = double(end - start) / double(CLOCKS_PER_SEC);

	std::cout << "After:	";
	pe.displayContainer(vector.begin(), vector.end());

	start = clock();
	pe.mergeSort(deque);
	end = clock();
	double time_taken2 = double(end - start) / double(CLOCKS_PER_SEC);

	std::cout << "Time : " << std::fixed << time_taken1 << " sec " << std::endl;
	std::cout << "Time : " << std::fixed << time_taken2 << " sec " << std::endl;

	return 0;
}