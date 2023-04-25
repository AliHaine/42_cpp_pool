#include <iostream>
#include <fstream>


 void writeToNewFile(std::ofstream& newFile, char *str) {
	newFile.write(str, strlen(str));
}

 void readSrcFile(std::ifstream& srcFile, std::ofstream& newFile, const std::string replaceStr[2]) {
	const int size = replaceStr[0].length();
	char* str = (char*) malloc(sizeof(char) * (size + 1));

	while (srcFile.good()) {
		srcFile.read(str, size);
		str[srcFile.gcount()] = '\0';
		std::cout << str << " /" << replaceStr[0]  << "/" << std::endl;
		if (std::string(str) == replaceStr[0]) {
			str = strcpy(str, replaceStr[1].c_str());
			std::cout << "condition" << std::endl;
		}
		writeToNewFile(newFile, str);
	}
}

int main(int argc, char *argv[]) {
	std::ofstream newFile;
	std::ifstream srcFile;
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
	readSrcFile(srcFile, newFile, replaceStr);
}
