#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _rank(1) {
    std::cout << "Default Bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int rank) : _name(name) {
    setRank(rank);
    std::cout << "Default Bureaucrat constructor" << std::endl;
}


Bureaucrat::Bureaucrat(Bureaucrat &bureaucrat) {
    std::cout << "Bureaucrat copy called" << std::endl;
    this->_rank = bureaucrat._rank;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &bureaucrat) {
    std::cout << "Bureaucrat copy assign called" << std::endl;
    this->_rank = bureaucrat._rank;
    return *this;
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat& bureaucrat) {
    ostream << bureaucrat._name << ", bureaucrat grade " << bureaucrat._rank;
    return ostream;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string Bureaucrat::getName(void) {
    return this->_name;
}

void Bureaucrat::setRank(int rank) {
    if (rank < 1)
        throw GradeTooHighException();
    else if (rank > 150)
        throw GradeTooLowException();
    this->_rank = rank;
}

int Bureaucrat::getRank(void) {
    return this->_rank;
}

void Bureaucrat::upRank(void) {
    setRank(getRank() - 1);
}

void Bureaucrat::downRank(void) {
    setRank(getRank() + 1);
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
    } catch (std::exception &e) {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because his rank is to low";
    }
    form.setSigned();
    std::cout << this->getName() << " signed " << form.getName();

}