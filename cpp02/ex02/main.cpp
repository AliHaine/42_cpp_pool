#include "Fixed.hpp"

int main(void) {
	Fixed a = Fixed(8);
    Fixed b = Fixed(9);
    Fixed z;
    std::cout << "a is " << a << std::endl;
    a = a + 1 ;
    std::cout << "a is " << a << std::endl;
    if (a == b)
        std::cout << "yes a equals b" << std::endl;
    else
        std::cout << "no a don't equals b" << std::endl;
    if (a > b)
        std::cout << "yes a is greater than b" << std::endl;
    else
        std::cout << "no a is not geater than b" << std::endl;
    a = a + 5;
    if (a > b)
        std::cout << "yes a is greater than b" << std::endl;
    else
        std::cout << "no a is not geater than b" << std::endl;
    if (a < b)
        std::cout << "yes a is lower than b" << std::endl;
    else
        std::cout << "no a is not lower than b" << std::endl;

    std::cout << "z is " << z << std::endl;
    z++;
    std::cout << "z is " << z << std::endl;
    ++z;
    std::cout << "z is " << z << std::endl;
	return 0;
}