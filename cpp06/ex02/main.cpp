#include "Base.hpp"
#include <cstdlib>
#include <time.h>


Base *generate(void) {
	srand (time(NULL));
	int	randValue = rand() % 3;

	if (randValue == 0)
		return new A();
	else if (randValue == 1)
		return new B();
	else
		return new C();
}

int main(void) {
	Base *base;

	base = generate();
	(void)base;
	return 0;
}
