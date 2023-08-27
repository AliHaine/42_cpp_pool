#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : _target(target) {
	(void)_target;
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) {
	std::cout << executor << std::endl;
}
