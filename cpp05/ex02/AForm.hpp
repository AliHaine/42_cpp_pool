#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	AForm(void);
	AForm(const std::string name, int rankToSign, int rankToExec);
	AForm(AForm &form);
	AForm &operator=(AForm &form);
	~AForm(void);

    const std::string   getName(void);
    bool                getIsSigned(void);
    int                 getRankToSign(void);
    int                 getRankToExec(void);
    void                setSigned(void);

	void                beSigned(Bureaucrat bureaucrat);
	virtual void		execute(const Bureaucrat &executor) = 0;

private:
    const std::string   _name;
    bool                _isSigned;
    const int           _rankToSign;
    const int           _rankToExec;

	class GradeTooLowException : public std::exception {
		const char *what(void) const throw() {
			return ("Form Grade too low");
		}
	};
};

#endif
