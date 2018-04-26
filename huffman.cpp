#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <iomanip>

struct Node {
	Node(int ch, int fq, int weight, Node* left, Node* right) {
		this->ch = ch;
		this->fq = fq;
		this->left = left;
		this->right = right;
		this->weight = weight;
	};
	int ch;
	int fq;
	int weight;
	Node* left;
	Node* right;
};

struct Compare {
    bool operator() (Node* a, Node* b) {
		return a->weight > b->weight;
	}
};

void traverse(Node* root, std::string code, std::ofstream& file);
int fileSize = 0;

int main() {

	std::priority_queue<Node*, std::vector<Node*>, Compare> huffTable;

	while (!std::cin.eof()) {

	    std::string line;
	    std::getline(std::cin, line);

	    if (line != "") {
		    std::string ch = line.substr(0, line.find('\t'));
		    std::string fq = line.substr(line.find('\t') + 1, line.length() - ch.length() - 1);
		    Node* node = new Node(stoi(ch), stoi(fq), stoi(fq), NULL, NULL);
		    huffTable.push(node);
	    }

	    if (std::cin.fail())
	        break;
	}

	while (huffTable.size() > 1) {
		Node* node1 = huffTable.top();
		huffTable.pop();

		Node* node2 = huffTable.top();
		huffTable.pop();

		Node* newNode = new Node(-1, -1, node1->weight + node2->weight, node1, node2);
		huffTable.push(newNode);
	}


	std::ofstream file; file.open ("codewords.txt");

	traverse(huffTable.top(), "", file);
	
	file.close();

	std::cout << fileSize << std::endl;

	return 0;
}

void traverse(Node* root, std::string code, std::ofstream& file) {

	if (root->left == NULL && root->right == NULL) {
		file << root->ch << "\t" << code << "\n";
		fileSize += code.length() * root->fq;
		return;
	}

	if (root->left != NULL)
		traverse(root->left, code + "0", file);

	if (root->right != NULL)
		traverse(root->right, code + "1", file);

}
