#include "Serialize.hpp"

int main(void) {
    Serialize s;
    Data d;
    uintptr_t uint;

    d.value = 5;
    std::cout << "value: " << d.value << " " << &d << std::endl;

    uint = s.serialize(&d);
    std::cout << "value: " << uint << " " << &uint << std::endl;
    return 0;
}
