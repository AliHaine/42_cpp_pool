#include "iter.h"

int main(void) {
	int a[] = {5, 4, 3, 2};
	double b[] = {8.9, 5.7, 2.3, 3.5};

	iter(&a[0], 4, upNumber<int>);
	for (int i = 0; i < 4; i++)
		std::cout << a[i] << std::endl;
	iter(&b[0], 4, upNumber<double>);
	for (int i = 0; i < 4; i++)
		std ::cout << b[i] << std::endl;
	return 0;
}