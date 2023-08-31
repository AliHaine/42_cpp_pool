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

static AForm *createShrubberyForm(std::string target) {
	return new ShrubberyCreationForm(target);
}
static AForm *createPresidentialForm(std::string target) {
	return new ShrubberyCreationForm(target);
}
static AForm *createRobotomyForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string form, std::string target) {
	AForm *(*ptr_tab[])(std::string) = {&createShrubberyForm, &createPresidentialForm, &createRobotomyForm};
	std::string formName[] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
	for (int i = 0; i < 3; i++) {
		if (form == formName[i]) {
			std::cout << "Intern create " << form << std::endl;
			return (ptr_tab[i])(target);
		}
	}
	std::cout << "the form " << form << " don't exist" << std::endl;
	return (0);
}