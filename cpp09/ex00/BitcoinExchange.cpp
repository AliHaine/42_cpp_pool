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

void BitcoinExchange::isValueValid(const std::string value) {
	float val = 0;
    try {
		val = stof(value);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
		throw ValueException();
    }
    if (val > 1000 || val < 0)
        throw ValueException();
}

std::string BitcoinExchange::getDate(void) const {
    return this->_date;
}

float BitcoinExchange::getValue(void) const {
    return this->_value;
}

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &bitcoinExchange) {
	os << "Date: " << bitcoinExchange.getDate() << " Value: " << bitcoinExchange.getValue();
	return os;
}