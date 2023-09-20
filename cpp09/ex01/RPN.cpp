#include "RPN.h"

RPN::RPN(void) {
	std::cout << "42 norm.." << std::endl;
}

RPN::RPN(const RPN &rpn) {
	(void)rpn;
	std::cout << "42 norm.." << std::endl;
}

RPN &RPN::operator=(const RPN &rpn) {
	(void)rpn;
	std::cout << "42 norm.." << std::endl;
	return (*this);
}

RPN::~RPN(void) {
	std::cout << "42 norm.." << std::endl;
}
