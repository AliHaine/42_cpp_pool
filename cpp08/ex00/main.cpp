#include "easyfind.h"

int main(void) {
	int i[] = {5, 2, 1, 3};
	try {
		std::cout << "value found at occurence: " << easyfind(i, 5) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}