#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat b1;
	ShrubberyCreationForm form("jardin");
	PresidentialPardonForm pform("myTarget");
	RobotomyRequestForm rform("targettt");
    try {
        Bureaucrat b2("Test b2", 55555);
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
	std::cout << std::endl;
    try {
        b1.downRank();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    Bureaucrat b3("Test b3", 1);
	b3.executeForm(form);
	std::cout << std::endl;
    std::cout << b3 << std::endl;
	b3.signForm(form);
	b3.executeForm(form);
	std::cout << std::endl;
	b1.setRank(138);
	b1.executeForm(form);
	std::cout << std::endl;
	b1.signForm(pform);
	b3.signForm(pform);
	b3.executeForm(pform);
	std::cout << std::endl;
	std::cout << rform <<std::endl;
	b3.signForm(rform);
	b3.executeForm(rform);
	b3.executeForm(rform);
	b3.executeForm(rform);
	std::cout << rform <<std::endl;
	std::cout << std::endl;
}