#include "Serialize.hpp"

int main(void) {
    Serialize s;
	uint32_t u;
    Data d;
	Data *d2;

    d.value = 5;
    std::cout << "value: " << d.value << " " << &d << std::endl;

	u = s.serialize(&d);
	std::cout << "Hexa value: " << u << std::hex << " Decimal value: " << u << std::dec << std::endl;
	std::cout << u << std::endl;
	d2 = s.deserialize(u);
	std::cout << "value: " << d2->value << std::endl;
    return 0;
}
