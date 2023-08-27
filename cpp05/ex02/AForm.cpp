#include "AForm.hpp"

AForm::AForm(void) : _name("Default"), _isSigned(false), _rankToSign(1), _rankToExec(1) {
    std::cout << "Forn Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, int rankToSign, int rankToExec) : _name(name), _isSigned(false), _rankToSign(rankToSign), _rankToExec(rankToExec) {
    std::cout << "Forn constructor called" << std::endl;
}

AForm::AForm(AForm &AForm) : _name(AForm.getName()), _isSigned(AForm.getIsSigned()), _rankToSign(AForm.getRankToSign()), _rankToExec(AForm._rankToExec) {
    std::cout << "Form copy constructor called" << std::endl;
}

AForm &AForm::operator=(AForm &form) {
    this->_isSigned = form.getIsSigned();
    std::cout << "Form copy assign constructor called" << std::endl;
    return *this;
}

AForm::~AForm(void) {
    std::cout << "AForm destructor called" << std::endl;
}

const std::string AForm::getName(void) {
    return this->_name;
}

bool AForm::getIsSigned(void) {
    return this->_isSigned;
}

int AForm::getRankToSign(void) {
    return this->_rankToSign;
}

int AForm::getRankToExec(void) {
    return this->_rankToExec;
}

void AForm::setSigned(void) {
    this->_isSigned = true;
}

void AForm::beSigned(Bureaucrat bureaucrat) {
    if (bureaucrat.getRank() > this->getRankToSign())
        throw GradeTooLowException();
    setSigned();
}