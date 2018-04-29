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
	while (!std::cin.eof()) {
	    char ch;
		std::cin >> std::noskipws >> ch;

		if (!std::cin.eof() || ch != '\n') {
			std::string strcode = table[std::to_string(ch)];
			int length = strcode.length();
			int mask = 0x0001 << length;
		    int code = std::stoi(strcode, nullptr, 2);
			code = mask | code;

			// std::cout << strcode << std::endl;
			// std::cout << std::bitset<8>(code).to_string() << std::endl;

			auto bitset = std::bitset<8>(code);
			unsigned char encode = static_cast<char>(bitset.to_ulong());
			std::cout << encode;
		}
	}

	return 0;
}
