#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _rank(0), _name("Default") {
    std::cout << "Default Bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &bureaucrat) {
    std::cout << "Bureaucrat copy called" << std::endl;
    this->_name = bureaucrat._name;
    this->_rank = bureaucrat._rank;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &bureaucrat) {
    std::cout << "Bureaucrat copy assign called" << std::endl;
    this->_name = bureaucrat._name;
    this->_rank = bureaucrat._rank;
    return *this;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

void Bureaucrat::setName(int name) {
    this->_name = name;
}

std::string Bureaucrat::getName(void) {
    return this->_name;
}

void Bureaucrat::setRank(int rank) {
    this->_rank = rank;
}

int Bureaucrat::getRank(void) {
    return this->_rank;
}

void Bureaucrat::upRank(void) {
    this->_rank++;
}

void Bureaucrat::downRank(void) {
    this->_rank--;
}