#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>

template <class T>
class MutantStack : public std::stack<T> {
public:
    MutantStack(void);

    ~MutantStack(void);
private:
    std::stack<T> _stack;

};

#endif
