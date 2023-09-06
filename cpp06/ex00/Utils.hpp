#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <array>

class Utils {
private:
	Utils(void);
public:
	static bool haveDuplicateChar(const std::string str, const char c);
	static bool haveForbiddenChar(const std::string str, const std::string allowed);
	static bool containChar(const std::string str, const char c);
	static bool isNan(const std::string str);
	static bool isNanf(const std::string str);
};

#endif
