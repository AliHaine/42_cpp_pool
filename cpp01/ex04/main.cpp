#include <iostream>
#include <fstream>

 void writeToNewFile(std::fstream& srcFile, std::fstream& newFile, const std::string replaceStr[2]) {
	char* str;

	while (srcFile.read(str, 1)) {
		std::cout << str << std::endl;
	}
}

int main(int argc, char *argv[]) {
	std::fstream newFile;
	std::fstream srcFile;
	std::string newFileName;
	std::string replaceStr[2];

	if (argc > 4 || argc < 2)
		return 1;

	srcFile.open(argv[1], std::ios::in);
	if (!srcFile) {
		std::cout << "the file " << argv[1] << " does not exist" << std::endl;
		return 2;
	}

	newFileName = std::string(argv[1]) + ".replace";
	newFile.open(newFileName, std::ios::out);
	if (!newFile) {
		std::cout << "Failed to create the file " << argv[1] << std::endl;
		return 2;
	}
	replaceStr[0] = argv[2];
	replaceStr[1] = argv[3];
	writeToNewFile(srcFile, newFile, replaceStr);
}
