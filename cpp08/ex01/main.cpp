#include "Span.h"

int main(void) {
    Span span(6);
    Span span2(5);

    span.addNumber(2);
    span.displaySpan();
    span.addNumber(5);
    span.addNumber(8);
    span.addNumber(9);
    span.addNumber(45);
    span.addNumber(-98);
    Span span3(span);
    span.displaySpan();
    std::cout << "----------------" << std::endl;
    try {
        span2 = span;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    span2.displaySpan();
    std::cout << "----------------" << std::endl;
    span3.displaySpan();
    return 0;
}