#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <array>

class Utils {
public:
	static bool HaveDuplicateChar(const std::string str, char c);
	static bool HaveForbiddenChar(const std::string str, const std::string allowed);
	static bool isNan(const std::string str);
};

#endif
