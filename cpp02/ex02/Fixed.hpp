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

    bool operator>(const Fixed& next);
    bool operator<(const Fixed& next);
    bool operator>=(const Fixed& next);
    bool operator<=(const Fixed& next);
    bool operator==(const Fixed& next);
    bool operator!=(const Fixed& next);

    Fixed operator+(int val);
    Fixed operator-(int val);
    Fixed operator*(int val);
    Fixed operator/(int val);

    Fixed& operator++(void);
    Fixed operator++(int val);
    Fixed& operator--(void);
    Fixed operator--(int val);

	float	toFloat(void) const;
	int		toInt(void) const;
    static Fixed min(Fixed& f1, Fixed& f2);
    static const Fixed min(const Fixed& f1, const Fixed& f2);
    static Fixed max(Fixed& f1, Fixed& f2);
    static const Fixed max(const Fixed& f1, const Fixed& f2);
private:
	int					rawBits;
	static const int	bits = 8;

	int getRawBits(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif