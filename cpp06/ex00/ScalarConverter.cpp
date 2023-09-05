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
    if (Utils::haveForbiddenChar(sc.getArg(), "-+0123456789.f"))
        std::cout << "forbidden char" << std::endl;
    if (Utils::haveDuplicateChar(sc.getArg(), '.'))
        std::cout << "double ." << std::endl;
    if (Utils::haveDuplicateChar(sc.getArg(), 'f'))
        std::cout << "double f" << std::endl;
    if (Utils::haveDuplicateChar(sc.getArg(), '-'))
        std::cout << "double f" << std::endl;
    if (Utils::haveDuplicateChar(sc.getArg(), '+'))
        std::cout << "double f" << std::endl;
	sc.DefineType();
	std::cout << "args : " << arg << " type " << sc.getType() << std::endl;
}

void ScalarConverter::DefineType(void) {
	if (Utils::isNan(this->getArg()))
        setType(type_nanf);
    else if (this->getArg().length() == 1)
		setType(type_char);
	else if (Utils::containChar(this->getArg(), '.')) {
        if (this->getArg().back() == 'f')
            setType(type_float);
        else
            setType(type_double);
	} else
        setType(type_int);
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