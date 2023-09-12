#include "Span.h"

Span::Span(void) : _size(0) {
    std::cout << "Span default constructor called" << std::endl;
}

Span::Span(const unsigned int size) : _size(size) {
    std::cout << "Span constructor called" << std::endl;
	_elements.reserve(size);
}

Span::Span(const Span &span) : _size(span.getSize()) {
    this->_elements.reserve(span.getSize());
    for (unsigned int i = 0; i < span._elements.size(); i++)
        this->_elements.push_back(span._elements[i]);
}

Span &Span::operator=(const Span &span) {
    if (this->getSize() < span.getSize())
        throw CopyAssignException();
    this->_elements.clear();
	this->_elements.reserve(span.getSize());
    for (unsigned int i = 0; i < span._elements.size(); i++)
		this->_elements.push_back(span._elements[i]);
    return *this;
}

Span::~Span(void) {
    std::cout << "Span destructor called" << std::endl;
    this->_elements.clear();
}

void Span::addNumber(const int number) {
	if (this->_elements.size() == this->getSize())
		throw SpanFullException();
    this->_elements.push_back(number);
}

void Span::addNumbers(const int numberOfNumber) {
	if (static_cast<int>(this->_size) < numberOfNumber)
		throw SpanFullException();
	for (int i = 0; i < numberOfNumber; i++)
		this->_elements.push_back(i + 1);
}

int Span::shortestSpan(void) {
	int shortest;
	int	currentValue;

	if (this->_elements.size() < 2)
		throw NoSpanException();
	std::vector<int> copyElements(this->_elements);
	std::sort(copyElements.begin(), copyElements.end());
	std::vector<int>::iterator startIterator = copyElements.begin();

	while (*startIterator < 0)
		startIterator++;
	shortest = *(startIterator + 1) - *startIterator;
	while (startIterator + 1 != copyElements.end()) {
		currentValue = *(startIterator + 1) - *startIterator;
		if (currentValue < shortest)
			shortest = currentValue;
		startIterator++;
	}
	return shortest;
}

int Span::longestSpan() {
	int shortest;
	int	currentValue;

	if (this->_elements.size() < 2)
		throw NoSpanException();
	std::vector<int> copyElements(this->_elements);
	std::sort(copyElements.begin(), copyElements.end());
	std::vector<int>::iterator startIterator = copyElements.begin();

	while (*startIterator < 0)
		startIterator++;
	shortest = *(startIterator + 1) - *startIterator;
	while (startIterator + 1 != copyElements.end()) {
		currentValue = *(startIterator + 1) - *startIterator;
		if (currentValue > shortest)
			shortest = currentValue;
		startIterator++;
	}
	return shortest;
}


void Span::displaySpan(void) {
    for (unsigned int i = 0; i < this->_elements.size(); i++)
        std::cout << this->_elements[i] << std::endl;
}

unsigned int Span::getSize(void) const {
    return this->_size;
}