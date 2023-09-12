#include "Span.h"

Span::Span(void) : _size(0), _containNumbers(0), _elements(0) {
    std::cout << "Span default constructor called" << std::endl;
}

Span::Span(const unsigned int size) : _size(size), _containNumbers(0) {
    std::cout << "Span constructor called" << std::endl;

    this->_elements = new int[size];
}

Span::Span(const Span &span) : _size(span.getSize()), _containNumbers(span.getContainNumbers()) {
    this->_elements = new int[span.getSize()];
    for (unsigned int i = 0; i < this->_containNumbers; i++)
        this->_elements[i] = span._elements[i];
}

Span &Span::operator=(const Span &span) {
    if (this->getSize() < span.getSize())
        throw CopyAssignException();
    this->_containNumbers = span.getContainNumbers();
    delete[] this->_elements;
    this->_elements = new int[this->getSize()];
    for (unsigned int i = 0; i < span.getContainNumbers(); i++)
        this->_elements[i] = span._elements[i];
    return *this;
}

Span::~Span(void) {
    std::cout << "Span destructor called" << std::endl;
    delete[] this->_elements;
}

void Span::addNumber(const int number) {
    this->_elements[this->_containNumbers++] = number;
}

int Span::shortestSpan(void) {
    if (this->getContainNumbers() < 2)
        throw NoSpanException();
}

int Span::longestSpan() {
    if (this->getContainNumbers() < 2)
        throw NoSpanException();
}


void Span::displaySpan(void) {
    for (unsigned int i = 0; i < this->_containNumbers; i++)
        std::cout << this->_elements[i] << std::endl;
}

unsigned int Span::getSize(void) const {
    return this->_size;
}

unsigned int Span::getContainNumbers(void) const {
    return this->_containNumbers;
}