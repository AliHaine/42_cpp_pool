#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string arg) : _arg(arg){
	std::cout << "ScalarConverter constructor called" << std::endl;
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

void ScalarConverter::Convert(const std::string arg) {
	ScalarConverter sc(arg);
	sc.DefineType();
	std::cout << "args : " << arg << std::endl;
}

void ScalarConverter::DefineType(void) {
	if (Utils::isNan(this->getArg())) {
		setType(type_nanf);
		return;
	}
	else if (this->getArg().length() == 1) {
		setType(type_char);
		return;
	}

	if (Utils::haveDuplicateChar(this->getArg(), '.'))
		std::cout << "double ." << std::endl;
	if (Utils::haveDuplicateChar(this->getArg(), 'f'))
		std::cout << "double f" << std::endl;
	if (Utils::haveForbiddenChar(this->getArg(), "0123456789.f"))
		std::cout << "forbidden char" << std::endl;
	if (Utils::containChar(this->getArg(), '.')) {

	}
	//verif .
		//verif float
		//verif double
	//verif int

	//if (Utils::HaveForbiddenChar(this->getArg()), "0123456789.f")
}

std::string ScalarConverter::getArg(void) const {
	return this->_arg;
}

Type ScalarConverter::getType(void) {
	return this->_type;
}

void ScalarConverter::setType(Type type) {
	this->_type = type;
}