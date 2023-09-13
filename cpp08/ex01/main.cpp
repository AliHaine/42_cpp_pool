#include "Span.h"

int main(void) {
    Span span(6);
    Span span2(5);

    span.addNumber(2);
    span.displaySpan();
	try {
		span.longestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    span.addNumber(0);
    span.addNumber(8);
    span.addNumber(11);
    span.addNumber(45);
    span.addNumber(-98);
    Span span3(span);
	std::cout << "A----------------" << std::endl;
    span.displaySpan();
	std::cout << "B----------------" << std::endl;
	span3.displaySpan();
    std::cout << "C----------------" << std::endl;
    try {
        span2 = span;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    span2.displaySpan();
    std::cout << "D----------------" << std::endl;
	try {
		span.addNumber(99);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "E----------------" << std::endl;
	Span s4(10000);
	s4.addNumbers(10000);
	s4.displaySpan();
	std::cout << "F----------------" << std::endl;
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
    return 0;
}