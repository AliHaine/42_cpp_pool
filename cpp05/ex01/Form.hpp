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

    const std::string   getName(void);
    bool                getIsSigned(void);
    int                 getRankToSign(void);
    int                 getRankToExec(void);
    void                setSigned(void);

    void                beSigned(Bureaucrat bureaucrat);

private:
    const std::string   _name;
    bool                _isSigned;
    const int           _rankToSign;
    const int           _rankToExec;
};

class GradeTooLowException : std::exception {
    const char *what() const noexcept override{
        return ("Form Grade too low");
    }
};

#endif
