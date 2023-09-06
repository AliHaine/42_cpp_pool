#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include "Utils.hpp"

typedef enum {
	type_char,
	type_int,
	type_double,
	type_float,
	type_nan,
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
	void				ProcessCast(void);
	void				PrintCastResult(char c, int i, float f, double d);
	std::string			getArg(void) const;
	int					getArgLength(void) const;
	Type				getType(void);
	void				setType(Type type);
private:
	const std::string	_arg;
	const int			_argLength;
	Type				_type;

	class DuplicateChar : public std::exception {
		const char *what(void) const throw() {
			return "Duplicate char detected";
		}
	};

	class ForbiddenChar : public std::exception {
		const char *what(void) const throw() {
			return "Forbidden char detected";
		}
	};

	class FloatErrorOccured : public std::exception {
		const char *what(void) const throw() {
			return "Float error occured";
		}
	};

	class ErrorOccured : public std::exception {
		const char *what(void) const throw() {
			return "Error occured";
		}
	};
};


#endif
