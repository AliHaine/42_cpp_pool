#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat(void);
	WrongCat(const WrongCat& dog);
	WrongCat& operator=(const WrongCat& Cat);
	~WrongCat(void);

	void makeSound(void) const;
	std::string getType(void) const;
};

#endif
