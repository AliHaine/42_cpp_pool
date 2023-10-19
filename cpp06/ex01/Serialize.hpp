#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <stdint.h>
#include <iostream>

struct Data {
    int value;
	int a;
	int b;
	int c;
	int d;
};

class Serialize {
public:
	Serialize(void);
	Serialize(const Serialize &serialize);
	Serialize &operator=(const Serialize &serialize);
	~Serialize(void);

    uintptr_t serialize(Data *ptr);
    Data *deserialize(uintptr_t raw);
};

#endif
