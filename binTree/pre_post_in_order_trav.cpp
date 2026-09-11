#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* left;
    Node* right;

    Node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};


// PRE-ORDER: Root -> Left -> Right
void pre_order_traversal(Node* node)
{
    if(node == NULL)
    {
        return;
    }

    cout << node->value << " ";
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
}


// IN-ORDER: Left -> Root -> Right
void in_order_traversal(Node* node)
{
    if(node == NULL)
    {
        return;
    }

    in_order_traversal(node->left);
    cout << node->value << " ";
    in_order_traversal(node->right);
}


// POST-ORDER: Left -> Right -> Root
void post_order_traversal(Node* node)
{
    if(node == NULL)
    {
        return;
    }

    post_order_traversal(node->left);
    post_order_traversal(node->right);
    cout << node->value << " ";
}


int main()
{
    Node* root = new Node(3);
    Node* node1 = new Node(5);
    Node* node2 = new Node(7);
    Node* node3 = new Node(4);

    root->left = node1;
    root->right = node2;
    node1->left = node3;


    cout << "Pre-order: ";
    pre_order_traversal(root);
    cout << endl;

    cout << "In-order: ";
    in_order_traversal(root);
    cout << endl;

    cout << "Post-order: ";
    post_order_traversal(root);
    cout << endl;

    return 0;
}
