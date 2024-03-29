#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b1;
	Form form("TestForm1", 5, 5);
    try {
        Bureaucrat b2("Test b2", 55555);
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try {
        b1.downRank();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    Bureaucrat b3("Test b3", 1);

    std::cout << b3 << std::endl;
	b3.signForm(form);
	std::cout << form << std::endl;
}