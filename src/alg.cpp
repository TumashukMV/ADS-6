#include  "bst.h"
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>

BST<std::string> makeTree(char* filename)
{
  std::string word;
	std::ifstream file(filename);
	BST<std::string>* tree = new BST<std::string>;
	char tempStr = ' ';
	while (!file.eof()) {

} 
		while (tempStr < 65 && (!file.eof())) {
			file.get(tempStr);
		}

		while (tempStr >= 65 && (!file.eof())) {
			if (tempStr >= 65 && tempStr <= 90) {
				word += tempStr;
			}
			if (tempStr >= 97 && tempStr <= 122) {
				word += tempStr;
			}

			file.get(tempStr);
		}

		for (int i = 0; i < word.length(); i++) {
			if (word[i] >= 65 && word[i] <= 90)
				word[i] += 32;
		}

		(*tree).Add(word);
		word = "";
	}

	return *tree;
}
