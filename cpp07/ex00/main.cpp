#include "Whatever.h"

int main(void) {
	int a = 5;
	int b = 4;
	double d1 = 5.9;
	double d2 = 8.7;

	std::cout << "value a: " << a << " value b: " << b << std::endl;
	std::cout << "Highest value: " << max(a, b) << std::endl;
	std::cout << "Lowest value: " << min(a, b) << std::endl;
	swap(a, b);
	std::cout << "value a: " << a << " value b: " << b << std::endl;
	std::cout << "value d1: " << d1 << " value d2: " << d2 << std::endl;
	std::cout << "Highest value: " << max(d1, d2) << std::endl;
	std::cout << "Lowest value: " << min(d1, d2) << std::endl;
	return 0;
}