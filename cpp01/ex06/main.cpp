#include "Harl.hpp"

int convertLevelToInt(std::string level) {
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (level.compare(levels[i]) == 0) {
			return i;
		}
	}
	return levels->length() + 1;
}

int main(int argc, char *argv[]) {
	if (argc != 2)
		return (1);

	Harl harl = Harl();
	harl.complain(convertLevelToInt(argv[1]));

	return (0);
}