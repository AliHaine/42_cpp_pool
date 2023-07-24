#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	(void)argv;
	if (argc < 2)
		return (1);
	ScalarConverter::convert(0);
	return (0);
}
