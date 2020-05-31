#include <cassert>
#include <iostream>
using namespace std;
template<typename T>
class BST
{
public:
    struct Node
    {
        T value;
        int count;
        Node* left;
        Node* right;
    };
private:
    Node* root;
    Node* addNode(Node*, T);
    void  printTree(Node*);
    int   searchNode(Node*, T);
    int   depthTree(Node*);
public:
    BST();
    ~BST();
    void add(T);
    void print();
    int  search(T);
    int depth();

};
template<typename T>
BST<T>::BST() :root(nullptr) {}

template<typename T>
BST<T>::~BST()
{
}
template<typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
    }
    else if (root->value > value) {
        root->left = addNode(root->left, value);
    }
    else if (root->value < value) {
        root->right = addNode(root->right, value);
    }
    else
        root->count++;
    return root;
}

template<typename T>
void BST<T>::add(T value) {
    root = addNode(root, value);
}
template<typename T>
void BST<T>::printTree(Node* root) {
    if (root == nullptr)
        return;
    printTree(root->left);
    for (int i = 0; i < root->count; i++)
        cout << root->value << " ";
    printTree(root->right);
}

template<typename T>
void BST<T>::print() {
    printTree(root);
}
template<typename T>
int BST<T>::searchNode(Node* root, T value)
{
    if (root == nullptr)
        return 0;
    else if (root->value > value)
        return searchNode(root->left, value);
    else if (root->value < value)
        return searchNode(root->right, value);
    else
        return root->count;
}

template<typename T>
int BST<T>::search(T value)
{
    return searchNode(root, value);
}
template<typename T>
int BST<T>::depthTree(Node* root) {
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 0;
    int left = depthTree(root->left);
    int right = depthTree(root->right);
    if (left > right)
        return left + 1;
    else
        return right + 1;
}

template<typename T>
int BST<T>::depth() {
    return depthTree(root);
}
