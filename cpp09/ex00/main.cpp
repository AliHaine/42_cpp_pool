#include "BitcoinExchange.h"

int convertDateAndValueFromString(const std::string s, std::string &date, std::string &value) {
    const unsigned long pipePos = s.find_first_of('|');
    if (pipePos == std::string::npos)
        return -1;
	date.clear();
	value.clear();
    date = s.substr(0, pipePos - 1);
    value.insert(0, s, pipePos + 2);
    return 0;
}

void fillInputData(std::list<BitcoinExchange> &inputData, std::ifstream &inputFile) {
    std::string fileLine;
    std::string date;
    std::string value;

    std::getline(inputFile, fileLine);
    while (std::getline(inputFile, fileLine)) {
        convertDateAndValueFromString(fileLine, date, value);
		try {
			BitcoinExchange::isValueValid(value);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			continue;
		}
        inputData.push_back(BitcoinExchange(date, stof(value)));
    }

    for (std::list<BitcoinExchange>::iterator it = inputData.begin(); it != inputData.end(); it++)
        std::cout << *it << std::endl;
}

int main(void) {
    std::list<BitcoinExchange> inputData;
    std::ifstream inputFile("input.txt");
    fillInputData(inputData, inputFile);

    return 0;
}
