#include "Whatever.h"

int main(void) {
	int a = 5;
	int b = 4;
	Whatever w = Whatever();

	std::cout << "value a: " << a << " value b: " << b << std::endl;
	std::cout << "Highest value: " << w.max(a, b) << std::endl;
	std::cout << "Lowest value: " << w.min(a, b) << std::endl;
	w.swap(a, b);
	std::cout << "value a: " << a << " value b: " << b << std::endl;
	return 0;
}
