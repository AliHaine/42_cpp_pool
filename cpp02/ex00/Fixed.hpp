#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
	Fixed(void);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int val;
	static const int raw;
};

#endif
