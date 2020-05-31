#include  "bst.h"
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string.h>
#include  <ctype.h>

BST<std::string> makeTree(char* filename)
{
using namespace std;

BST<string> makeTree(char* filename)

} 
{

BST<string> tree1;
    ifstream file(filename);
    string str="", tmp="";
    while (file >> str)
{
    int flag = 0;
    for (int j = 0; j < str.size(); j++)
    {
        flag = 0;
        if ((str[j] >= 'a' && str[j] <= 'z') || (str[j] >= 'A' && str[j] <= 'Z'))
            tmp += (char)tolower(str[j]);
        else
            if (tmp != "")
            {
                tree1.add(tmp);
                tmp = "";
                flag = 1;
                continue;
            }
    }
    if (flag == 0 && tmp != "")
    {
        tree1.add(tmp);
        tmp = "";
    }
}
    return tree1;

}
