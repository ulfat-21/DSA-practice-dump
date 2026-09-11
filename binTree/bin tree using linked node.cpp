#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* left;
    Node* right;

    Node(int x)
    {
        this->value = x;
        this->left = NULL;
        this->right = NULL;
    }
};

int main()
{
    Node* root = new Node(3);
    Node* node1 = new Node(5);
    Node* node2 = new Node(7);

    root->left = node1;
    root->right = node2;

    cout << "Root: " << root->value << endl;
    cout << "Left child: " << root->left->value << endl;
    cout << "Right child: " << root->right->value << endl;

    return 0;
}
