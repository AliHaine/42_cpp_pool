#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
	virtual ~Animal(void);
	virtual void makeSound(void) const;
	virtual std::string getType(void) const;
protected:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal& animal);
	Animal& operator=(const Animal& animal);
	std::string type;
};

#endif
