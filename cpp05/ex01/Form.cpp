#include "Form.hpp"

Form::Form(void) : _name("Default"), _isSigned(false), _rankToSign(1), _rankToExec(1) {
    std::cout << "Forn Default constructor called" << std::endl;
}

Form::Form(const std::string name, int rankToSign, int rankToExec) : _name(name), _isSigned(false), _rankToSign(rankToSign), _rankToExec(rankToExec) {
    std::cout << "Forn constructor called" << std::endl;
}

Form::Form(Form &form) : _name(form.getName()), _isSigned(form.getIsSigned()), _rankToSign(form.getRankToSign()), _rankToExec(form._rankToExec) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(Form &form) {
    this->_isSigned = form.getIsSigned();
    std::cout << "Form copy assign constructor called" << std::endl;
    return *this;
}

Form::~Form(void) {
    std::cout << "Forn destructor called" << std::endl;
}

const std::string Form::getName(void) {
    return this->_name;
}

bool Form::getIsSigned(void) {
    return this->_isSigned;
}

int Form::getRankToSign(void) {
    return this->_rankToSign;
}

int Form::getRankToExec(void) {
    return this->_rankToExec;
}

void Form::setSigned(void) {
    this->_isSigned = true;
}

void Form::beSigned(Bureaucrat bureaucrat) {
    if (bureaucrat.getRank() > this->getRankToSign())
        throw GradeTooLowException();
    setSigned();
}