#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const int val);
	Fixed(const float val);
	~Fixed(void);
	Fixed(const Fixed& f);
	Fixed*	Fixed::operator=(Fixed& f);

	float	toFloat(void);
	int		toInt(void);
private:
	int					iVal;
	float				fVal;
	static const int	bits = 8;
}

#endif