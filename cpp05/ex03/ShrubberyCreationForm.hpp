#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(ShrubberyCreationForm &shrubberyCreationForm);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm &shrubberyCreationForm);
	~ShrubberyCreationForm(void);

	std::string			getTarget(void) const;
	void				execute(const Bureaucrat &executor) const;
private:
	const std::string	_target;
};

#endif