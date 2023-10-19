#include "easyfind.h"


int main(void) {
    std::list<int> l1;
    l1.push_back(8);
    l1.push_back(9);
    l1.push_back(15);
    l1.push_back(5);
	try {
		std::cout << "value found at occurrence: " << easyfind(l1, 51) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    try {
        std::cout << "value found at occurrence: " << easyfind(l1, 8) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "value found at occurrence: " << easyfind(l1, 5) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	return 0;
}