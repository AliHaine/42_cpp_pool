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

    std::string getDate(void) const;
    float       getValue(void) const;
private:
    const std::string   _date;
    const float         _value;

};


#endif
