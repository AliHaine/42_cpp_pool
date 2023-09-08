#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<class ELEMENT>
class Array {
public:
	Array(void) : _element(new ELEMENT[0]) ,_size(0) {}

	Array(unsigned int n) : _element(new ELEMENT[n]), _size(n) {}

	Array(const Array &array) : _element(new ELEMENT[array._size]), _size(array._size) {
		for (unsigned int i = 0; i < array._size; i++)
			this->_element[i] = array[i];
	}

	Array &operator=(const Array &array) {
		delete[] this->_element;
		this->_element = new ELEMENT[array._size];
		this->_size = array._size;
		for (unsigned int i = 0; i < array._size; i++)
			this->_element[i] = array[i];

	}

	ELEMENT &operator[](unsigned int i) const {
		if (i >= getSize())
			throw OutOfArray();
		return this->_element[i];
	}

	~Array(void){
		delete[] this->_element;
	};

	unsigned int	getSize(void) const {
		return this->_size;
	}
	void			setSize(unsigned int size) {
		this->_size = size;
	}
private:
	ELEMENT			*_element;
	unsigned int	_size;

	class OutOfArray : public std::exception {
		const char *what(void) const throw() {
			return "Out of range array exception";
		}
	};
};

#endif
