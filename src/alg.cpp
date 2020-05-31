#include  <locale>
#include  <cstdlib>

BST<std::string> makeTree(char* filename)
{

} 
BST<string> makeTree(char* filename) {
BST<string> tree;
    ifstream file(filename);
    string str,word;
    while (!file.eof()) {
        word.clear();
        file >> str;
        bool flag = 0;
        for (auto &letter : str) {
            if (isalpha(letter))
            {
                flag = 1;
                letter=tolower(letter);
                word += letter;
            }
            else if (flag)
            {
                tree.add(word);
                word.clear();
                flag = 0;
            }
        }
        if (!word.empty()) {
            tree.add(word);
        }
    }
    return tree;
}
