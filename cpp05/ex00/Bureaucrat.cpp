#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _rank(1) {
    std::cout << "Default Bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int rank) : _name(name), _rank(rank) {
    std::cout << "Default Bureaucrat constructor" << std::endl;
}


Bureaucrat::Bureaucrat(Bureaucrat &bureaucrat) {
    std::cout << "Bureaucrat copy called" << std::endl;
    this->_rank = bureaucrat._rank;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &bureaucrat) {
    std::cout << "Bureaucrat copy assign called" << std::endl;
    this->_rank = bureaucrat._rank;
    return *this;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string Bureaucrat::getName(void) {
    return this->_name;
}

void Bureaucrat::setRank(int rank) {
    this->_rank = rank;
}

int Bureaucrat::getRank(void) {
    return this->_rank;
}

void Bureaucrat::upRank(void) {
    setRank(getRank() + 1);
}

void Bureaucrat::downRank(void) {
    setRank(getRank() - 1);
}