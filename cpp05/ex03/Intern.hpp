#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
	Intern(void);
	Intern(Intern &intern);
	Intern &operator=(Intern &intern);
	~Intern(void);

	AForm *makeForm(std::string form, std::string target);
private:
	static ShrubberyCreationForm *createShrubberyForm(std::string target);
};

#endif
