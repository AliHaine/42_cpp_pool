#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default", 72, 45), _target("Default") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &robotomyRequestForm) : AForm(robotomyRequestForm.getTarget(), 145, 137), _target(robotomyRequestForm.getTarget()) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &robotomyRequestForm) {
	(void)robotomyRequestForm;
	std::cout << "RobotomyRequestForm copy assign constructor called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	static int i = 0;

	if (executor.getRank() > this->getRankToExec())
		throw GradeTooLowException();
	if (!this->getIsSigned())
		throw NotSignedException();
	if (i % 2 == 0)
		std::cout << "Brrrrrrrr " << this->getTarget() << " are now robotised "<< std::endl;
	else
		std::cout << "Operation to robotise" << this->getTarget() << " fail.. "<< std::endl;
	i++;
	std::cout << executor << " execute " << this->getName() << std::endl;
}

