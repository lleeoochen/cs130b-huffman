#include <iostream>
#include <vector>
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

void traverse(Node* root, std::string code);
void prettyPrint(Node* p, int indent);
int fileSize = 0;

int main() {

	std::vector<Node*> huffTable;

	while (!std::cin.eof()) {

	    std::string line;
	    std::getline(std::cin, line);

	    if (line != "") {
		    std::string ch = line.substr(0, line.find('\t'));
		    std::string fq = line.substr(line.find('\t') + 1, line.length() - ch.length() - 1);
		    Node* node = new Node(stoi(ch), stoi(fq), stoi(fq), NULL, NULL);
		    huffTable.push_back(node);
	    }

	    if (std::cin.fail())
	        break;
	}

	while (huffTable.size() > 1) {
		std::sort(huffTable.begin(), huffTable.end(), [](Node* a, Node* b) -> bool {
			return a->weight > b->weight;
		});

		// for (int i = 0; i < huffTable.size(); i++) {
		// 	std::cout << huffTable[i]->weight << " ";
		// }
		// std::cout << std::endl;

		Node* node1 = huffTable[huffTable.size() - 1];
		Node* node2 = huffTable[huffTable.size() - 2];
		huffTable.pop_back();
		huffTable.pop_back();
		std::cout << node1->ch << "\t" << node1->weight << std::endl;

		Node* newNode = new Node(-1, -1, node1->weight + node2->weight, node1, node2);
		huffTable.push_back(newNode);
	}

	traverse(huffTable[0], "");
	// prettyPrint(huffTable[0], 0);
	std::cout << fileSize << std::endl;
	return 0;
}

void traverse(Node* root, std::string code) {

	if (root->left == NULL && root->right == NULL) {
		// std::cout << root->fq << ", " << code << std::endl;
		fileSize += code.length() * root->fq;
		return;
	}

	if (root->left != NULL)
		traverse(root->left, code + "0");

	if (root->right != NULL)
		traverse(root->right, code + "1");

}

void prettyPrint(Node* p, int indent) {
    if(p != NULL) {
        
        if(p->right) {
            prettyPrint(p->right, indent+4);
        }
        
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        
        if (p->right)
        	std::cout<<" /\n" << std::setw(indent) << ' ';
        
        std::cout<< p->fq << "\n ";
        
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            prettyPrint(p->left, indent+4);
        }
    }
}