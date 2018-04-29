#include <iostream>
#include <fstream>
#include <bitset>
#include <map>
#include <string>


int main(int argc, char* argv[]) {

	//Open file of codewords
	std::string filename = argv[1];
	std::ifstream reader;
	reader.open(filename);

	//Get code words from file
	std::string word, code;
	std::map<std::string, std::string> table;
	while (reader >> word >> code)
	    table[word] = code;

	//Get input from std
	std::string allcode = "";
	while (!std::cin.eof()) {
	    char ch;
		std::cin >> std::noskipws >> ch;

		if (!std::cin.eof() || ch != '\n')
			allcode += table[std::to_string(ch)];
	}

	int offset = allcode.length() % 8;
	std::string padding = (allcode[allcode.length() - 1] == '0') ? "1" : "0";

	for (int i = 0; i < offset; i++)
		allcode += padding;

	// Output binary
	for (int i = 0; i < allcode.length(); i += 8) {
		auto bitset = std::bitset<8>(allcode.substr(i, 8));
		unsigned char encode = static_cast<char>(bitset.to_ulong());
		std::cout << encode;
	}

	return 0;
}
