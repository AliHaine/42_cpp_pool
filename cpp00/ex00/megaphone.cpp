#include <iostream>

int	main(int argc, char *argv[]) {
	int	i = 1;
	std::string s;

	if (argc == 1)
		return (1);
	while (argv[i]) {
		s = argv[i++];
		for (unsigned long int j = 0; j < s.length(); j++)
			s[j] = std::toupper(s[j]);
		std::cout << s;
	}
	return (0);
}
