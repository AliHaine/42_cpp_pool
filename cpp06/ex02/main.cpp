#include "Base.hpp"
#include <cstdlib>
#include <time.h>

Base *generate(void) {
	srand (time(NULL));
	int	randValue = rand() % 3;

	std::cout << "randValue " << randValue << std::endl;
	if (randValue == 0)
		return new A();
	else if (randValue == 1)
		return new B();
	else
		return new C();
}

void identify(Base *base) {
	if (dynamic_cast<A *>(base))
		std::cout << "Class A detected" << std::endl;
	else if (dynamic_cast<B *>(base))
		std::cout << "Class B detected" << std::endl;
	else if (dynamic_cast<C *>(base))
		std::cout << "Class C detected" << std::endl;
}

void identify(Base &base) {
	try {
		(void)dynamic_cast<A &>(base);
		std::cout << "Class A detected " << std::endl;
		return ;
	} catch (std::bad_cast &e) {}

	try {
		(void)dynamic_cast<B &>(base);
		std::cout << "Class B detected " << std::endl;
		return ;
	} catch (std::bad_cast &e) {}

	try {
		(void)dynamic_cast<C &>(base);
		std::cout << "Class C detected " << std::endl;
		return ;
	} catch (std::bad_cast &e) {}
}

int main(void) {
	Base *base;

	base = generate();
	identify(base);
	identify(*base);
	return 0;
}
