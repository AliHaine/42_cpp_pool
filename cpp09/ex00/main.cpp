#include "BitcoinExchange.h"

void convertDateAndValueFromString(const std::string s, std::string &date, std::string &value) {
    const unsigned long pipePos = s.find_first_of('|');
	date.clear();
	value.clear();
	if (pipePos == std::string::npos)
		return;
    date = s.substr(0, pipePos - 1);
    value.insert(0, s, pipePos + 2);
}

void fillInputData(std::list<BitcoinExchange> &inputData, std::ifstream &inputFile) {
    std::string fileLine;
    std::string date;
    std::string value;

    std::getline(inputFile, fileLine);
    while (std::getline(inputFile, fileLine)) {
        convertDateAndValueFromString(fileLine, date, value);
        inputData.push_back(BitcoinExchange(date, value));
    }
}

void processCalc(std::list<BitcoinExchange> &inputData) {
    std::ifstream fileData("data.csv");
    float       valueSave;
    std::string currentDate;
    float       value;

    std::getline(fileData, currentDate);
    std::getline(fileData, currentDate);
	for (std::list<BitcoinExchange>::iterator it = inputData.begin(); it != inputData.end(); it++) {
		try {
			it->isValueValid();
            it->isDateValid();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			continue;
		}
        do {
            std::cout << "date " << currentDate << std::endl;
            value = stof(currentDate.substr(currentDate.find_first_of(',') + 1, currentDate.length()));
            currentDate.erase(currentDate.find_first_of(','), std::to_string(value).length());
            it->compressDate(currentDate, '-');
            if (it->getDateCompressed() >= currentDate) {
                if (it->getDateCompressed() > currentDate)
                    value = valueSave;
                break;
            }
            valueSave = value;
            currentDate.clear();
        } while (std::getline(fileData, currentDate));
		std::cout << it->getDate() << " => " << it->getValue() << " = " << value * std::stof(it->getValue())  << std::endl;
	}
}

int main(void) {
    std::list<BitcoinExchange> inputData;
    std::ifstream inputFile("input.txt");
    fillInputData(inputData, inputFile);
	processCalc(inputData);

    return 0;
}
