#include "Array.h"

int main(void) {
	Array<int> ar(10);
	for (int i = 0; i < 10; i++)
		ar[i] = i;
	Array<int> ar2(ar);
	std::cout << "AR2 value: " << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << ar2[i] << std::endl;
	std::cout << "" << std::endl;
	try {
		std::cout << ar[3] << std::endl;
		std::cout << ar[8] << std::endl;
		std::cout << ar[9] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << ar[10] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Array<int> ar3 = ar;
	std::cout << "AR3 value: " << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << ar3[i] << std::endl;
	try {
		std::cout << ar3[-1] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}