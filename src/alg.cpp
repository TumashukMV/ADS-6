#include  "bst.h"
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
using namespace std;
#include <cctype> 

BST<std::string> makeTree(char* filename)
{

} 
	BST<std::string>BS;
	ifstream f;
	f.open(filename);
	string s = "", temp = "";
	int i = 0;
	bool flag = false;
	while (f >> s)
	{
		for (int j = 0; j < s.size(); j++)
		{
			flag = false;
			if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))
				temp += (char)tolower(s[j]);
			else
			{
				if (temp != "")
				{
					BS.add(temp);
					temp = "";
					flag = true;
					continue;
				}
			}
		}
		if (flag == false && temp != "")
		{
			BS.add(temp);
			temp = "";
		}
	}
	return BS;
}
