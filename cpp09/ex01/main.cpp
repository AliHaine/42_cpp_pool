#include "RPN.h"

void calcFunction(std::stack<int> &sta, const char ope) {
	int a = sta.top();
	sta.pop();
	int b = sta.top();
	sta.pop();
	switch(ope) {
		case '+':
			sta.push(b + a);
			break;
		case '-':
			sta.push(b - a);
			break;
		case '*':
			sta.push(b * a);
			break;
		case '/':
			sta.push(b / a);
			break;
	}
}

void rpnFunction(std::string& argv) {
	std::stack<int> sta;

	for (std::string::const_iterator it = argv.begin(); it != argv.end(); it++) {
		if (*it == ' ')
			continue ;
		if (*it == '-' || *it == '+' || *it == '/' || *it == '*') {
			if (sta.size() != 2) {
				std::cout << "Error" << std::endl;
				return;
			}
			calcFunction(sta, *it);
			continue;
		}
		sta.push(*it - 48);
	}
	std::cout << "Result: " << sta.top() << std::endl;
}

int argvCheck(const std::string str) {
	for (int i = 0; i < int(str.length()); i++) {
		if (i % 2 == 1) {
			if (str[i] != ' ')
				return 0;
		} else if (str[i] != '-' && str[i] != '+' && str[i] != '/' && str[i] != '*' && !isdigit(str[i]))
			return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	if (argc < 2 || !argvCheck(argv[1])) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	rpnFunction(argv[1]);
	return 0;
}
