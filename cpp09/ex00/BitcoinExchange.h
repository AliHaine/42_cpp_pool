#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include <ctime>

class BitcoinExchange {
public:
    BitcoinExchange(void);
    BitcoinExchange(const std::string date, const std::string value);
    BitcoinExchange(const BitcoinExchange &bitcoinExchange);
    BitcoinExchange &operator=(const BitcoinExchange &bitcoinExchange);
	bool operator<(const BitcoinExchange &b1) const;
    ~BitcoinExchange(void);

    void compressDate(std::string &date, char delimiter);
	int compareDate(std::string dateSrc, std::string dateTarget);

	void isValueValid(void);
	void isDateValid(void);
    std::string getDate(void) const;
    std::string getValue(void) const;
    std::string getDateCompressed(void) const;

	friend std::ostream &operator<<(std::ostream &os, const BitcoinExchange &bitcoinExchange);

	class NoValueException : public std::exception {
		const char *what(void) const throw() {
			return "Exception: No Value found.";
		}
	};

	class ValueConvertException : public std::exception {
		const char *what(void) const throw() {
			return "Exception: Value can't be convert to float: ";
		}
	};

	class ValueOverException : public std::exception {
		const char *what(void) const throw() {
			return "Exception: Value are too large or to low: ";
		}
	};

    class DateInputException : public std::exception {
        const char *what(void) const throw() {
            return "Exception: Bad input: ";
        }
    };

    class DateException : public std::exception {
        const char *what(void) const throw() {
            return "Exception: invalid date: ";
        }
    };
private:
    const std::string   _date;
    const std::string   _value;
    std::string         _dateCompressed;

};


#endif
