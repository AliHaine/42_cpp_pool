#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
public:
	Bureaucrat(void);
	Bureaucrat(Bureaucrat& bureaucrat);
	Bureaucrat& operator=(Bureaucrat& bureaucrat);
	~Bureaucrat(void);

	std::string getName(void);
	void		setName(std::string name);
	int			getRank(void);
	void		setRank(int rank);

private:
	std::string const	_name;
	int					_rank;
};


#endif
