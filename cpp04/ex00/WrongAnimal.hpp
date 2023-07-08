#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& wrongAnimal);
	WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
	virtual ~WrongAnimal(void);
	void makeSound(void) const;
	virtual std::string getType(void) const;
protected:
	std::string type;
};

#endif
