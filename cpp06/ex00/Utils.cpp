#include "Utils.hpp"

bool Utils::haveDuplicateChar(const std::string str, char c) {
	int	counter;

	counter = 0;
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
		if (*it == c)
		{
			if (counter >= 1)
				return true;
			counter++;
		}
	}
	return false;
}

bool Utils::haveForbiddenChar(const std::string str, const std::string allowed) {
	for (std::string::const_iterator it_str = str.begin(); it_str != str.end(); it_str++) {
		for (std::string::const_iterator it_allowed = allowed.begin(); it_allowed != allowed.end(); it_allowed++) {
			if (*it_str == *it_allowed)
				break;
			if (it_allowed + 1 == allowed.end())
				return true;
		}
	}
	return false;
}


bool Utils::containChar(const std::string str, const char c) {
	for (std::string::const_iterator it_str = str.begin(); it_str != str.end(); it_str++) {
		if (*it_str == c)
			return true;
	}
	return false;
}

bool Utils::isNan(const std::string str) {
	int i = 0;

	const std::string tabs[] = {"-inff", "+inff", "nanf", "-inf", "+inf","nan", ""};
	while (!tabs[i].empty()) {
		if (str.compare(tabs[i++]) == 0)
			return true;
	}
	return false;
}

