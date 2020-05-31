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
	char str = ' ';
	while (!file.eof()) 
   {
		while (str < 'A' && (!file.eof()))
	  {
			file.get(str);
		}
		while (str >= 'A' && (!file.eof()))
		{
			if (str >= 'A' && str <= 'Z')
			{
				word += str;
			}
			if (str >= 'a' && str <= 'z')
			{
				word += str;
			}
			file.get(str);
		}
		for (int i = 0; i < word.length(); i++)
		{
			if (word[i] >= 'A' && word[i] <= 'Z')
				word[i] += 32;
		}
		(*tree).add(word);
		word = "";
	}
	return *tree;
}
}

