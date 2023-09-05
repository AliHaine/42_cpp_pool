#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	(void)argv;
	if (argc < 2)
		return (1);
	ScalarConverter::Convert(argv[1]);

	return (0);
}
