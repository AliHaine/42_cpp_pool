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
	this->rawBits = f.getRawBits();
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = f.getRawBits();
	return *this;
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
    this->rawBits = this->getRawBits() + (val << this->bits);
    return *this;
}

Fixed Fixed::operator-(int val) {
    this->rawBits = this->getRawBits() - (val << this->bits);
    return *this;
}

Fixed Fixed::operator*(int val) {
    this->rawBits = this->getRawBits() * val;
    return *this;
}

Fixed Fixed::operator/(int val) {
    this->rawBits = this->getRawBits() / val;
    return *this;
}

Fixed& Fixed::operator++(void) {
    ++this->rawBits;
    return *this;
}

Fixed Fixed::operator++(int val) {
    ++(*this);
    return *this;
}

Fixed& Fixed::operator--(void) {
    --this->rawBits;
    return *this;
}

Fixed Fixed::operator--(int val) {
    --(*this);
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

Fixed Fixed::min(Fixed &f1, Fixed &f2) {
    if (f1.getRawBits() < f2.getRawBits())
        return f1;
    return f2;
}

const Fixed Fixed::min(const Fixed &f1, const Fixed &f2) {
    if (f1.getRawBits() < f2.getRawBits())
        return f1;
    return f2;
}

Fixed Fixed::max(Fixed &f1, Fixed &f2) {
    if (f1.getRawBits() > f2.getRawBits())
        return f1;
    return f2;
}

const Fixed Fixed::max(const Fixed &f1, const Fixed &f2) {
    if (f1.getRawBits() > f2.getRawBits())
        return f1;
    return f2;
}


