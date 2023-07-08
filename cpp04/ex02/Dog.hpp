#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal {
public:
	Dog(void);
	Dog(const Dog& dog);
	Dog& operator=(const Dog& dog);
	~Dog(void);

	void makeSound(void) const;
	std::string getType(void) const;
private:
	Brain* brain;
};

#endif
