#include "PmergeMe.h"



int main(int argc, char *argv[]) {
    std::vector<unsigned int> vector;
    for (int i = 1; i < argc; i++) {
        int val = atoi(argv[i]);
        if (val <= 0) {
            std::cout << "Error" << std::endl;
            return 1;
        }
        vector.push_back(val);
    }
    for (std::vector<unsigned int>::iterator it = vector.begin(); it != vector.end(); it++)
        std::cout << *it << std::endl;
    return 1;
}