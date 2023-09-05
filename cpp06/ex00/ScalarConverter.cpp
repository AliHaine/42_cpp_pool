#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _arg("42"), _argLength(2) {
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string arg) : _arg(arg), _argLength(arg.length()) {
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter& scalarConverter) : _arg(scalarConverter.getArg()), _argLength(scalarConverter.getArgLength()) {
	std::cout << "ScalarConverter constructor copy called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& scalarConverter) {
	this->setType(scalarConverter.getType());
	std::cout << "ScalarConverter assign copy called" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::Convert(const std::string arg) {
	ScalarConverter sc(arg);
	if (sc.getArg().find_first_of('-') != std::string::npos && sc.getArg().find_first_of('-') != 0)
		throw ForbiddenChar();
	if (sc.getArg().find_first_of('+') != std::string::npos && sc.getArg().find_first_of('+') != 0)
		throw ForbiddenChar();
	if (Utils::haveDuplicateChar(sc.getArg(), '.'))
		throw DuplicateChar();
	if (Utils::haveDuplicateChar(sc.getArg(), '-'))
		throw DuplicateChar();
	if (Utils::haveDuplicateChar(sc.getArg(), '+'))
		throw DuplicateChar();
	sc.DefineType();
	if (sc.getType() != type_char)
		if (Utils::haveForbiddenChar(sc.getArg(), "-+0123456789.f"))
			throw ForbiddenChar();
	sc.ProcessCast();
}

void ScalarConverter::DefineType(void) {
	int	firstOfPoint;

	if (Utils::isNan(this->getArg()))
        setType(type_nanf);
    else if (this->getArgLength() == 1)
		setType(type_char);
	else if (Utils::containChar(this->getArg(), '.')) {
		firstOfPoint = this->getArg().find_first_of('.');

		if (firstOfPoint + 1 == this->getArgLength())
			throw ErrorOccured();
		if (this->getArg().at(firstOfPoint + 1) == '0')
			if (this->getArgLength() > firstOfPoint + 2)
				if (this->getArg().at(firstOfPoint + 2) > '0'
					&& this->getArg().at(firstOfPoint + 2) <= '9')
					throw ErrorOccured();
		if (Utils::containChar(this->getArg(), 'f')) {
			if (this->getArg().back() != 'f' || Utils::haveDuplicateChar(this->getArg(), 'f')
				|| this->getArg().at(this->getArgLength() - 2) == '.')
				throw FloatErrorOccured();
			setType(type_float);
		} else {
			setType(type_double);
		}
	} else
		setType(type_int);
}

void ScalarConverter::ProcessCast(void) {
	char	c;
	int		i;
	float	f;
	double	d;

	if (this->getType() == type_nanf) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		return ;
	} else if (this->getType() == type_char) {
		c = static_cast<char>(this->getArg().at(0));
		i = static_cast<int>(c);
		d = static_cast<double>(c);
		f = static_cast<float>(c);
	} else if (this->getType() == type_int) {
		i = static_cast<int>(strtol(this->getArg().c_str(), nullptr, 0));
		c = static_cast<char>(i);
		d = static_cast<double>(i);
		f = static_cast<float>(i);
	} else if (this->getType() == type_float) {
		f = static_cast<float>(strtof(this->getArg().c_str(), nullptr));
		i = static_cast<int>(f);
		c = static_cast<char>(f);
		d = static_cast<double>(f);
	} else if (this->getType() == type_double) {
		d = static_cast<double>(atof(this->getArg().c_str()));
		f = static_cast<float>(d);
		i = static_cast<int>(d);
		c = static_cast<char>(d);
	}
	this->PrintCastResult(c, i, f, d);
}

void ScalarConverter::PrintCastResult(char c, int i, float f, double d) {
	std::string	floatCompensator = "f";
	std::string doubleCompensator = "";

	if (this->getArg().at(this->getArg().find_first_of('.') + 1) == '0'
		|| this->getType() == type_int || this->getType() == type_char) {
		floatCompensator.insert(0, ".0");
		doubleCompensator.insert(0, ".0");
	}
	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << floatCompensator << std::endl;
	std::cout << "double: " << d << doubleCompensator << std::endl;
}

std::string ScalarConverter::getArg(void) const {
	return this->_arg;
}

int	ScalarConverter::getArgLength(void) const {
	return (this->_argLength);
}

Type ScalarConverter::getType(void) {
	return this->_type;
}

void ScalarConverter::setType(Type type) {
	this->_type = type;
}