#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain) {
	std::cout << "Copy constructor called" << std::endl;
	std::copy(brain.ideas, brain.ideas + 100, this->ideas);
}

Brain &Brain::operator=(const Brain &brain) {
	std::cout << "Copy assign constructor called" << std::endl;
	std::copy(brain.ideas, brain.ideas + 100, this->ideas);
	return *this;
}

Brain::~Brain(void) {
	std::cout << "Brain Destructor called" << std::endl;
}