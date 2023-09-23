#include "BitcoinExchange.h"

void convertDateAndValueFromString(const std::string s, std::string &date, std::string &value) {
    const unsigned long pipePos = s.find_first_of('|');
	date.clear();
	value.clear();
	if (pipePos == std::string::npos) {
		date = s;
		value = "0";
		return;
	}
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
	inputData.sort();
}

void processCalc(std::list<BitcoinExchange> &inputData) {
    std::ifstream   fileData("data.csv");
    std::string     currentDate;
    float           value;
	float           valueSave;

    std::getline(fileData, currentDate);
    std::getline(fileData, currentDate);
	for (std::list<BitcoinExchange>::iterator it = inputData.begin(); it != inputData.end(); it++) {
		try {
			it->isValueValid();
            it->isDateValid();
		} catch (std::exception &e) {
			std::cout << e.what() << it->getDate() << " " << it->getValue() << std::endl;
			continue;
		}

        do {
			value = stof(currentDate.substr(currentDate.find_first_of(',') + 1, currentDate.length()));
			int comparisonResult = it->compareDate(currentDate, it->getDate());
			if (comparisonResult < 2) {
				if (comparisonResult == 0)
					value = valueSave;
				break;
			}
			valueSave = value;
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
