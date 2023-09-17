#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange(void) : _date("none"), _value(0) {
    std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string date, const float value) : _date(date), _value(value) {
    std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange) : _date(bitcoinExchange._date), _value(bitcoinExchange._value) {
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinExchange) {
    (void)bitcoinExchange;
    std::cout << "BitcoinExchange copy assign constructor called" << std::endl;
    return *this;
}

BitcoinExchange::~BitcoinExchange(void) {
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

std::string BitcoinExchange::getDate(void) const {
    return this->_date;
}

float BitcoinExchange::getValue(void) const {
    return this->_value;
}