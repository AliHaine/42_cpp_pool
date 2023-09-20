#ifndef RPN_H
#define RPN_H

#include <stack>
#include <iostream>

class RPN {
public:
	RPN(void);
	RPN(const RPN &rpn);
	RPN &operator=(const RPN &rpn);
	~RPN(void);
};


#endif
