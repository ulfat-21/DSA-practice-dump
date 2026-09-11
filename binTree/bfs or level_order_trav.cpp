#include <iostream>
#include <queue>
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


void level_order_traversal(Node* node)
{
    queue<Node*> q;

    q.push(node);

    while(!q.empty())
    {
        Node* current_node = q.front();
        q.pop();

        cout << current_node->value << " ";

        if(current_node->left != NULL)
        {
            q.push(current_node->left);
        }

        if(current_node->right != NULL)
        {
            q.push(current_node->right);
        }
    }
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

    cout << "Level-order: ";
    level_order_traversal(root);

    return 0;
}
