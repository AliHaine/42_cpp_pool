#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default", 145, 137), _target("Default") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &shrubberyCreationForm) : AForm(shrubberyCreationForm.getTarget(), 145, 137), _target(shrubberyCreationForm.getTarget()) {
	std::cout << "ShruberryCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &shrubberyCreationForm) {
	(void)shrubberyCreationForm;
	std::cout << "ShruberryCreationForm copy assign constructor called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (executor.getRank() > this->getRankToExec())
		throw GradeTooLowException();
	if (!this->getIsSigned())
		throw NotSignedException();
	std::ofstream file(this->getTarget());
	file << "       /\\\n"
				 "      //\\\\\n"
				 "     //  \\\\\n"
				 "    //    \\\\\n"
				 "   //      \\\\\n"
				 "  //        \\\\\n"
				 " //__________\\\\\n"
				 "      || ||\n"
				 "      || ||";
	std::cout << executor << " execute " << this->getName() << std::endl;
}
