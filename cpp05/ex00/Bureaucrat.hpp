#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
public:
	Bureaucrat(void);
    Bureaucrat(std::string name, int rank);
	Bureaucrat(Bureaucrat &bureaucrat);
	Bureaucrat& operator=(Bureaucrat &bureaucrat);

	~Bureaucrat(void);

	const std::string getName(void);
    void		setRank(int rank);
	int			getRank(void);
    void        upRank(void);
    void        downRank(void);

private:
	const std::string	_name;
	int					_rank;
};


#endif
