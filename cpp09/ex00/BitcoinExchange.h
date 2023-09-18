#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <list>
#include <fstream>

class BitcoinExchange {
public:
    BitcoinExchange(void);
    BitcoinExchange(const std::string date, const float value);
    BitcoinExchange(const BitcoinExchange &bitcoinExchange);
    BitcoinExchange &operator=(const BitcoinExchange &bitcoinExchange);
    ~BitcoinExchange(void);


    static void        isValueValid(std::string value);
    std::string getDate(void) const;
    float       getValue(void) const;


	friend std::ostream &operator<<(std::ostream &os, const BitcoinExchange &bitcoinExchange);

	class ValueException : public std::exception {
    	const char *what(void) const throw() {
    		return "Value exception";
    }
};
private:
    const std::string   _date;
    const float         _value;

};


#endif
