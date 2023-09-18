#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange(void) : _date("none"), _value(0) {
    std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string date, const std::string value) : _date(date), _value(value) {
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

void BitcoinExchange::isValueValid(void) {
	float val = 0;

	if(this->getValue().empty())
		throw NoValueException();
    try {
		val = stof(this->getValue());
    } catch (std::exception &e) {
		throw ValueConvertException();
    }
    if (val > 1000 || val < 0)
        throw ValueOverException();
}

void BitcoinExchange::isDateValid(void) {
	int date[3];

	(void)date;
}

std::string BitcoinExchange::getDate(void) const {
    return this->_date;
}

std::string BitcoinExchange::getValue(void) const {
    return this->_value;
}

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &bitcoinExchange) {
	os << "Date: " << bitcoinExchange.getDate() << " Value: " << bitcoinExchange.getValue();
	return os;
}