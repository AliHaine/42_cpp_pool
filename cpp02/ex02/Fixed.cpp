#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = val << this->bits;
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf((val * (1 << this->bits)));
}

Fixed::Fixed(const Fixed& f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = f.getRawBits();
	return *this;
}

float Fixed::toFloat(void) const {
	return (float)this->getRawBits() / (1 << this->bits);
}

int Fixed::toInt(void) const {
	return this->getRawBits() >> this->bits;
}

int Fixed::getRawBits(void) const {
	return this->rawBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& next) {
    if (this->getRawBits() > next.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<(const Fixed& next) {
    if (this->getRawBits() < next.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed& next) {
    if (this->getRawBits() >= next.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed& next) {
    if (this->getRawBits() <= next.getRawBits())
        return true;
    return false;
}

bool Fixed::operator==(const Fixed& next) {
    if (this->getRawBits() == next.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed& next) {
    if (this->getRawBits() != next.getRawBits())
        return true;
    return false;
}

Fixed Fixed::operator+(int val) {
    Fixed f;

    f.rawBits = this->getRawBits() + (val << this->bits);
    return f;
}

Fixed Fixed::operator-(int val) {
    Fixed f;

    f.rawBits = this->getRawBits() - (val << this->bits);
    return f;
}

Fixed Fixed::operator*(int val) {
    Fixed f;

    f.rawBits = this->getRawBits() * val;
    return f;
}

Fixed Fixed::operator/(int val) {
    Fixed f;

    f.rawBits = this->getRawBits() / val;
    return f;
}

Fixed& Fixed::operator++(void) {
    std::cout << "apl1" << std::endl;
    this->rawBits = 1 / (1 << this->bits);
    return *this;
}

Fixed Fixed::operator++(int val) {
    Fixed f;

    std::cout << "apl2" << std::endl;
    f.rawBits = 50000;
   // this->rawBits = this->getRawBits() + (1 / (1 << this->bits));
    //std::cout << this->rawBits << std::endl;
    return f;
}


