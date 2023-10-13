#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	AForm(void);
	AForm(const std::string name, int rankToSign, int rankToExec);
	AForm(AForm &form);
	AForm &operator=(AForm &form);
	virtual ~AForm(void) = 0;

    std::string			getName(void) const;
    bool                getIsSigned(void) const;
	int					getRankToSign(void) const;
    int					getRankToExec(void)const ;
    void                setSigned(void);

	void                beSigned(const Bureaucrat &bureaucrat);
	virtual void		execute(const Bureaucrat &executor) const = 0;

private:
    const std::string   _name;
    bool                _isSigned;
    const int           _rankToSign;
    const int           _rankToExec;

protected:
	class GradeTooLowException : public std::exception {
		const char *what(void) const throw() {
			return ("Form Grade too low");
		}
	};

	class NotSignedException : public std::exception {
		const char *what(void) const throw() {
			return ("Form is not signed");
		}
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &aForm);

#endif
