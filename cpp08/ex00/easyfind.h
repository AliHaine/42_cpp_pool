#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <list>

class NoValueFound : public std::exception {
    const char *what(void) const throw() {
        return "No occurence found exception";
    }
};

template <typename T>
int easyfind(T t, int value) {
    int i = 0;

    for (std::list<int>::iterator it = t.begin(); it != t.end(); it++) {
        if (*it == value)
            return i;
        i++;
    }
    throw NoValueFound();
}

#endif