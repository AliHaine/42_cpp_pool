#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange(void) : _date("0"), _value(0), _dateCompressed("0") {
    std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string date, const std::string value) : _date(date), _value(value) {
    this->_dateCompressed = this->getDate();
    compressDate(this->_dateCompressed, '-');
    std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange) : _date(bitcoinExchange._date), _value(bitcoinExchange._value), _dateCompressed(bitcoinExchange._dateCompressed) {
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinExchange) {
    this->_dateCompressed = bitcoinExchange._dateCompressed;
    std::cout << "BitcoinExchange copy assign constructor called" << std::endl;
    return *this;
}

bool BitcoinExchange::operator<(const BitcoinExchange &b1) const {
	return this->getDateCompressed() < b1.getDateCompressed();
}

BitcoinExchange::~BitcoinExchange(void) {
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::compressDate(std::string &date, char delimiter) {
    date.erase(std::remove(date.begin(), date.end(), delimiter), date.end());
}

int BitcoinExchange::compareDate(std::string dateSrc, std::string dateTarget) {
	dateSrc.erase(10, dateSrc.length());
	dateSrc.erase(std::remove(dateSrc.begin(), dateSrc.end(), '-'), dateSrc.end());

	dateTarget.erase(10, dateTarget.length());
	dateTarget.erase(std::remove(dateTarget.begin(), dateTarget.end(), '-'), dateTarget.end());

	if (atoi(dateSrc.c_str()) > atoi(dateTarget.c_str()))
		return 0;
	else if (atoi(dateSrc.c_str()) == atoi(dateTarget.c_str()))
		return 1;
	return 2;
}

void BitcoinExchange::isValueValid(void) {
	float val;

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

    if (this->getDate().length() != 10)
        throw DateInputException();
    if (!strptime(this->getDate().c_str(), "%Y-%d-%m", &tm))
        throw DateException();
    if (atoi(this->getDateCompressed().c_str()) > 20220329 || atoi(this->getDateCompressed().c_str()) < 20090102)
        throw DateException();
}


std::string BitcoinExchange::getDate(void) const {
    return this->_date;
}

std::string BitcoinExchange::getValue(void) const {
    return this->_value;
}

std::string BitcoinExchange::getDateCompressed() const {
    return this->_dateCompressed;
}

std::ostream &operator<<(std::ostream &os, const BitcoinExchange &bitcoinExchange) {
	os << "Date: " << bitcoinExchange.getDate() << " Value: " << bitcoinExchange.getValue();
	return os;
}