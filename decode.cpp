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
	while (reader >> word >> code)
	    table[code] = word;

	//Get offset identifier
	char firstByte;
	std::cin >> std::noskipws >> firstByte;
	int offset = int(std::bitset<8>(firstByte).to_ulong());

	//Get input from std
	std::string leftover = "";
	while (!std::cin.eof()) {

		//Initialize codes bytes
		std::string code1 = "", code2 = "", code3 = "";
		char byte1, byte2, byte3;

		//Read first byte
		std::cin >> std::noskipws >> byte1;
		code1 = std::bitset<8>(byte1).to_string();

		//Handle first byte
		if (std::cin.eof())
			break; //Ignore the last byte since it's duplicated.

		//Read second byte
		std::cin >> std::noskipws >> byte2;
		code2 = std::bitset<8>(byte2).to_string();

		//Handle second byte
		if (std::cin.eof()) {
			code2 = ""; //Ignore the 2nd byte and keep 1st byte
		}
		else {

			//Read third byte
			std::cin >> std::noskipws >> byte3;
			code3 = std::bitset<8>(byte3).to_string();

			//Handle third byte
			if (std::cin.eof())
				code3 = ""; //Ignore third byte and keep 1st and 2nd bytes.
		}

		//Combine all bytes
		code = code1 + code2 + code3;
		code = leftover + code;
		leftover = "";

		//Match and print the original words
		std::string subcode = "";
		for (int i = 0; i < code.length(); i++) {
			subcode += code[i];

			//Exit if we meet the padding offset
			if (std::cin.eof() && (code.length() - i) == offset) {
				break;
			}

			//Try to match and print codeword
			if (table.count(subcode) >= 1) {
				char word = stoi(table[subcode]);
				std::cout << word;
				subcode = "";
			}
		}

		//Send leftover bytes to next inputs
		leftover = subcode;
	}

	return 0;
}
