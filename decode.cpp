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
	std::string leftover = "", prevCode = "";
	while (!std::cin.eof()) {

	    char ch;
		std::cin >> std::noskipws >> ch;
		std::string code = std::bitset<8>(ch).to_string();

		prevCode = code;
		code = leftover + code;
		leftover = "";

		std::string subcode = "";
		for (int i = 0; i < code.length(); i++) {

			subcode += code[i];
			if (table.count(subcode) >= 1) {

				char word = stoi(table[subcode]);
				if (!std::cin.eof() || code != prevCode)
					std::cout << word;

				subcode = "";
			}
		}

		leftover = subcode;
	}

	return 0;
}
