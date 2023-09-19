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
    struct tm tm;
	int date[3];
    (void)date;

	if (this->getDate().length() != 10)
        throw DateInputException();

    for (int i = 0; i < static_cast<int>(this->getDate().length()); i++) {
        if (this->getDate()[i] == '-') {
            if (i != 4 && i != 7)
                throw DateInputException();
        } else if (!isdigit(this->getDate()[i]))
            throw DateInputException();
    }
    if (strptime(this->getDate().c_str(), "%Y-%m-%d", &tm))
        std::cout << "date is valid" << std::endl;
    else
        std::cout << "date is invalid" << std::endl;

    date[0] =  atoi(this->getDate().substr(0, 4).c_str());
    date[1] = atoi(this->getDate().substr(5, 7).c_str());
    date[2] = atoi(this->getDate().substr(8, 10).c_str());
    if (date[0] < 1900 || date[0] > 2023 || date[1] < 1 || date[1] > 12)
        throw DateException();
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