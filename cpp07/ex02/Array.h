#ifndef ARRAY_H
#define ARRAY_H

template<typename ELEMENT>
class Array {
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &array);
	Array &operator=(const Array &array);
	~Array(void);
private:
	ELEMENT			element;
	unsigned int	size;
};

#endif
