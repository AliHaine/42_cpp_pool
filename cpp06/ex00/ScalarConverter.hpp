#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
public:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter& scalarConverter);
	ScalarConverter& operator=(ScalarConverter& scalarConverter);
	~ScalarConverter(void);

	static void convert(char c);
};


#endif
