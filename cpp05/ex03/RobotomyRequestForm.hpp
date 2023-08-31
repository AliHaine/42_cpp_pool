#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(RobotomyRequestForm &robotomyRequestForm);
	RobotomyRequestForm &operator=(RobotomyRequestForm &robotomyRequestForm);
	~RobotomyRequestForm(void);

	std::string			getTarget(void) const;
	void				execute(const Bureaucrat &executor) const;
private:
	const std::string	_target;
};

#endif
