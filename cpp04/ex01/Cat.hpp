#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal {
public:
	Cat(void);
	Cat(const Cat& dog);
	Cat& operator=(const Cat& Cat);
	~Cat(void);

	void makeSound(void) const;
	std::string getType(void) const;
private:
	Brain* brain;
};

#endif
