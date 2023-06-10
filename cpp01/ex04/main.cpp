#include <iostream>
#include <fstream>

 void replaceWordInStr(std::string& str, const std::string replaceStr[2], size_t pos) {
	 if (pos < str.length()) {
		 str.erase(pos, replaceStr[0].length());
	 }
	 str.insert(pos, replaceStr[1]);
}

 void readSrcFile(std::ifstream& srcFile, std::ofstream& newFile, const std::string replaceStr[2]) {
	std::string str;
	size_t pos;

	while (getline(srcFile, str)) {
		pos = str.find(replaceStr[0], 0);
		while (pos != std::string::npos) {
			replaceWordInStr(str, replaceStr, pos);
			pos = str.find(replaceStr[0], 0);
		}
		newFile.write(str.c_str(), str.length());
		newFile.write("\n", 1);
	}
}

int main(int argc, char *argv[]) {
	std::ofstream newFile;
	std::ifstream srcFile;
	std::string newFileName;
	std::string replaceStr[2];

	if (argc != 4) {
		std::cerr << "args error, please try again" << std::endl;
		return 1;
	}
	srcFile.open(argv[1], std::ios::in);
	if (!srcFile) {
		std::cerr << "the file " << argv[1] << " does not exist" << std::endl;
		return 2;
	}

	newFileName = std::string(argv[1]) + ".replace";
	newFile.open(newFileName, std::ios::out);
	if (!newFile) {
		std::cerr << "Failed to create the file " << argv[1] << std::endl;
		return 2;
	}
	replaceStr[0] = argv[2];
	replaceStr[1] = argv[3];
	readSrcFile(srcFile, newFile, replaceStr);
}
