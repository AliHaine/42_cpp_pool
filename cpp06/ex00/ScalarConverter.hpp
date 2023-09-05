#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include "Utils.hpp"

typedef enum {
	type_char,
	type_int,
	type_double,
	type_float,
	type_nanf,
}	Type;

class ScalarConverter {
public:
	ScalarConverter(void);
	ScalarConverter(const std::string arg);
	ScalarConverter(ScalarConverter& scalarConverter);
	ScalarConverter& operator=(ScalarConverter& scalarConverter);
	~ScalarConverter(void);

	static void			Convert(std::string str);
	void				DefineType(void);
	std::string			getArg(void) const;
	Type				getType(void);
	void				setType(Type type);
private:
	const std::string	_arg;
	Type				_type;
};


#endif
