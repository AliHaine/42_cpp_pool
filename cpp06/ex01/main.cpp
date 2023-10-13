#include "Serialize.hpp"

int main(void) {
    Serialize s;
	uintptr_t u;
    Data d;
	Data *d2;

    d.value = 5;
    std::cout << "value: " << d.value << " Adresse d: " << &d << std::endl;

	u = s.serialize(&d);
	std::cout << "Hexa value: " << u << std::hex << " Decimal value: " << u << std::dec << std::endl;
	d2 = s.deserialize(u);
	std::cout << "Adresse d2: " << d2->value << std::endl;
    return 0;
}
