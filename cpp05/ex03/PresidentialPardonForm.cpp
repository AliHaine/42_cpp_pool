#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default", 25, 5), _target("Default") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &presidentialPardonForm) : AForm(presidentialPardonForm.getTarget(), 145, 137), _target(presidentialPardonForm.getTarget()) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &presidentialPardonForm) {
	(void)presidentialPardonForm;
	std::cout << "PresidentialPardonForm copy assign constructor called" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (executor.getRank() > this->getRankToExec())
		throw GradeTooLowException();
	if (!this->getIsSigned())
		throw NotSignedException();
	std::cout << this->getTarget() << " is pardonned by Zaphod Beeblebrox" << std::endl;
	std::cout << executor << " execute " << this->getName() << std::endl;
}