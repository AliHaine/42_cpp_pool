#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
    Form(void);
    Form(const std::string name, int rankToSign, int rankToExec);
    Form(Form &form);
    Form &operator=(Form &form);
    ~Form(void);

    std::string   		getName(void) const;
    bool                getIsSigned(void) const ;
    int                 getRankToSign(void) const;
    int                 getRankToExec(void) const;
    void                setSigned(void);

    void                beSigned(Bureaucrat bureaucrat);

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

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif