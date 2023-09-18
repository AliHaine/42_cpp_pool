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
	for (std::list<BitcoinExchange>::iterator it = inputData.begin(); it != inputData.end(); it++) {
		try {
			it->isValueValid();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			continue;
		}
		std::cout << it->getDate() << " => " << it->getValue() << " = " << std::endl;
	}
}

int main(void) {
    std::list<BitcoinExchange> inputData;
    std::ifstream inputFile("input.txt");
    fillInputData(inputData, inputFile);
	processCalc(inputData);

    return 0;
}
