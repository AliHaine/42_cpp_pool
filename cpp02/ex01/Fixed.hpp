#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed(void);
	Fixed(const int val);
	Fixed(const float val);
	Fixed(const Fixed& f);
	~Fixed(void);
	Fixed& operator=(const Fixed& f);

	float	toFloat(void) const;
	int		toInt(void) const;
private:
	int					rawBits;
	static const int	bits = 8;

	int getRawBits(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif