#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
public:
	Harl(void);
	~Harl(void);
	void complain(int);
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void nothing(void);
};

#endif
