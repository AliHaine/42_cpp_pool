#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {

public:
	Bureaucrat(void);
    Bureaucrat(std::string name, int rank);
	Bureaucrat(Bureaucrat &bureaucrat);
	Bureaucrat &operator=(Bureaucrat &bureaucrat);
	~Bureaucrat(void);

	std::string			getName(void) const;
    void		        setRank(int rank);
	int		        	getRank(void) const;
    void                upRank(void);
    void                downRank(void);
    void                signForm(Form &form);

private:
	const std::string	_name;
	int					_rank;

	class GradeTooHighException : public std::exception {
		const char *what(void) const throw() {
			return "Grade Too High";
		}
	};

	class GradeTooLowException : public std::exception {
		const char *what(void) const throw() {
			return "Grade Too Low";
		}
	};
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif