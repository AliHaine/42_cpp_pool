#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern &intern) {
	(void)intern;
	std::cout << "Intern copy constructo called" << std::endl;
}

Intern &Intern::operator=(Intern &intern) {
	(void)intern;
	std::cout << "Intern copy assign constructo called" << std::endl;
	return *this;
}

Intern::~Intern(void) {
	std::cout << "Intern destructor called" << std::endl;
}

static ShrubberyCreationForm *createShrubberyForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string form, std::string target) {
	(void)form;

	ShrubberyCreationForm *(*ptr_tab[1])(std::string) = {&createShrubberyForm};
	std::cout << "make" << std::endl;
	return (*ptr_tab[0])(target);
}