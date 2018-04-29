#include <iostream>
#include <fstream>
#include <bitset>
#include <unordered_map>
#include <string>


int main(int argc, char* argv[]) {

	//Open file of codewords
	std::string filename = argv[1];
	std::ifstream reader;
	reader.open(filename);

	//Get code words from file
	std::string word, code;
	std::unordered_map<std::string, std::string> table;
	while (reader >> word >> code) {
	    table[code] = word;
	}

	//Get input from std
	while (!std::cin.eof()) {
	    char ch;
		std::cin >> std::noskipws >> ch;
		std::string code = std::to_string(std::stoi(std::bitset<8>(ch).to_string()));
		code = code.substr(1, code.length() - 1);

		// if (my_map[k1].find(k2) != my_map[k1].end())

		char word = stoi(table[code]);
		if (!std::cin.eof() || word != '\n')
			std::cout << word;
	}

	// std::cout << std::endl;

	return 0;
}
