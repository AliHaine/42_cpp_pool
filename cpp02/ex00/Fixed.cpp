#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(f.getRawBits());
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return rawBits;
}

Fixed *Fixed::operator=(const Fixed &f) {
    this->setRawBits(f.getRawBits());
    std::cout << "Copy assignment operator called" << std::endl;
    return this;
}

void Fixed::setRawBits(int value) {
    this->rawBits = value;
}