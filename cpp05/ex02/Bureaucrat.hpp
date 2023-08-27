#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

public:
	Bureaucrat(void);
    Bureaucrat(std::string name, int rank);
	Bureaucrat(Bureaucrat &bureaucrat);
	Bureaucrat &operator=(Bureaucrat &bureaucrat);
    friend std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);
	~Bureaucrat(void);

	const std::string   getName(void);
    void		        setRank(int rank);
	int		        	getRank(void);
    void                upRank(void);
    void                downRank(void);
    void                signForm(AForm &form);

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

#endif
