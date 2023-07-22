#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	std::cout << "ScalarConverter default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter& scalarConverter) {
	(void)scalarConverter;
	std::cout << "ScalarConverter constructor copy called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& scalarConverter) {
	(void)scalarConverter;
	std::cout << "ScalarConverter assign copy called" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::convert(char c) {
	(void)c;
}