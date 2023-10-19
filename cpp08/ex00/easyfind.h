#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <list>
#include <algorithm>

class NoValueFound : public std::exception {
    const char *what(void) const throw() {
        return "No occurence found exception";
    }
};

template <typename T>
int easyfind(T t, int value) {
	typename T::iterator it = std::find(t.begin(), t.end(), value);
	if (it == t.end())
		throw NoValueFound();
	return std::distance(t.begin(), it);
}

#endif