#include <iostream>

int	main(int argc, char *argv[]) {
	int	i = 1;
	std::string s;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	while (argv[i]) {
		s = argv[i++];
		for (unsigned long int j = 0; j < s.length(); j++)
			s[j] = std::toupper(s[j]);
		std::cout << s << std::endl;
	}
	return (0);
}
