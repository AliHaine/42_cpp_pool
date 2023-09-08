#ifndef ITER_H
#define ITER_H

#include <iostream>

template<typename T>
void upNumber(T &a) {
	a++;
}

template<typename T1, typename T2, typename T3>
void iter(T1 *a, const T2 l, const T3 func) {
	for (T2 i = 0; i < l; i++) {
		func(*a++);
	}
}

#endif
