#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>

class NoValueFound : public std::exception {
	const char *what(void) const throw() {
		return "No occurence found exception";
	}
};

template <typename T>
int easyfind(T t, int value) {
	int	i = 0;

	while (t) {
		if (*t++ == value)
			return i;
		i++;
	}
	throw NoValueFound();
}

#endif