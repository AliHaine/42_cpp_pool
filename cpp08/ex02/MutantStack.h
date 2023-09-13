#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>
#include <vector>

template <class T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::deque<T>::iterator container;
	container begin() {
		return this->c.begin();
	}
	container end() {
		return this->c.end();
	}
};

#endif
