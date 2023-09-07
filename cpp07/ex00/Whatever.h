#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

class Whatever {
public:
	Whatever(void){};
	Whatever(const Whatever &whatever){};
	Whatever &operator=(const Whatever &whatever){return *this;};
	~Whatever(void);

	void swap(int &a, int &b) {
		int	temp = a;

		a = b;
		b = temp;
	}
	int min(int a, int b) {
		if (b <= a)
			return b;
		return a;
	}
	int max(int a, int b) {
		if (b >= a)
			return b;
		return a;
	}
};

#endif