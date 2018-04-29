#include <iostream>
#include <unordered_map>

int main() {

	std::unordered_map<int, int> table;
	char lastCh = ' ';

	while (!std::cin.eof()) {
	    char ch;
		std::cin >> std::noskipws >> ch;
		lastCh = ch;

		if (!table.count(ch))
			table[ch] = 0;
		table[ch] = table[ch] + 1;
	}

	if (lastCh == '\n')
		table['\n']--;

	for (auto i : table ) {
		int key = i.first;
		int value = i.second;
		std::cout << key << "\t" << value << std::endl;
	}

	return 0;
}
