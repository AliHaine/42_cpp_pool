#ifndef SPAN_H
#define SPAN_H

#include <iostream>

class Span {
public:
    Span(void);
    Span(const unsigned int size);
    Span(const Span &span);
    Span &operator=(const Span &span);
    ~Span(void);

    void    addNumber(const int number);
    int     shortestSpan(void);
    int     longestSpan(void);
    void    displaySpan(void);

    unsigned int        getSize(void) const;
    unsigned int        getContainNumbers(void) const;

private:
    const unsigned int  _size;
    unsigned int        _containNumbers;
    int                 *_elements;
    int                 _shortesSpan;
    int                 _longestSpan;

    class CopyAssignException : public std::exception {
        const char *what(void) const throw() {
            return "Copy assign exception, size to low";
        }
    };

    class NoSpanException : public std::exception {
        const char *what(void) const throw() {
            return "No span can be found";
        }
    };
};


#endif
