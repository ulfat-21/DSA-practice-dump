#include<iostream>
#include<queue>
using namespace std;

class Node
{
public:
    int value;
    Node* left;
    Node* right;
    Node* parent;

    Node(int x)
    {
        this->value = x;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};

Node* root = NULL;

void deleteBST(int x)
{
    Node* current_node = root;
    /// Search for node with value = x
    while(current_node != NULL)
    {
        if(x == current_node->value){
            break;
        }
        else if(x < current_node->value){
            current_node = current_node->left;
        }
        else if(x > current_node->value){
            current_node = current_node->right;
        }
    }
    /// Case-4: root == NULL or
    /// Case-5: Value not found in BST
    if(current_node == NULL){
        return;
    }
    /// Case-3: Node has 2 children
    if(current_node->left != NULL && current_node->right != NULL){
        Node* successor = current_node->right;
        while(successor->left != NULL)
        {
            successor = successor->left;
        }
        current_node->value = successor->value;
        current_node = successor;
        /// Now, the node to be deleted (current_node) has either 0 or 1 children
    }
    /// Case-1 and Case-2: Node has 0 or 1 children
    Node* child_node = NULL;
    if(current_node->left != NULL){
        child_node = current_node->left;
    }
    if(current_node->right != NULL){
        child_node = current_node->right;
    }
    /// Setting parent pointer of child_node (if not NULL) to current_node's parent
    if(child_node != NULL){
        child_node->parent = current_node->parent;
    }
    /// Case-6: Checking if the node to be deleted is the root
    if(current_node == root){
        root = child_node;
    }
    else if(current_node->parent->left == current_node){
        current_node->parent->left = child_node;
    }
    else{
        current_node->parent->right = child_node;
    }
    delete current_node;
}

void insertBST(int x)
{
    /// Case-1: BST is empty
    if(root == NULL){
        root = new Node(x);
        return;
    }
    Node* current_node = root;
    /// Search for correct parent node to insert new value
    while(true)
    {
        /// Case-2: Value already exists in BST. Return (NO INSERTION)
        if(x == current_node->value){
            return;
        }
        /// Break before current_node becomes NULL
        else if(x < current_node->value){
            if(current_node->left == NULL) break;
            current_node = current_node->left;
        }
        else if(x > current_node->value){
            if(current_node->right == NULL) break;
            current_node = current_node->right;
        }
    }
    /// Required Parent Node Found (here, current_node), Check where to insert, left or right.
    /// Also, set parent pointer of the new Node to current_node
    Node* newNode = new Node(x);
    newNode->parent = current_node;
    if(x < current_node->value) {
        current_node->left = newNode;
    }
    else{
        current_node->right = newNode;
    }
}

/// Additional parent_node parameter required
Node* insertBST_recursive(int x, Node* current_node, Node* parent_node=NULL)
{
    if(current_node == NULL){
        Node* newNode = new Node(x);
        newNode->parent = parent_node;
        return newNode;
    }
    if(x == current_node->value){
        return current_node;
    }
    else if(x < current_node->value){
        current_node->left = insertBST_recursive(x, current_node->left, current_node);
    }
    else{
        current_node->right = insertBST_recursive(x, current_node->right, current_node);
    }
    return current_node;
}

Node* searchBST(int x)
{
    Node* current_node = root;
    while(current_node != NULL)
    {
        if(x == current_node->value){
            return current_node;
        }
        else if(x < current_node->value){
            current_node = current_node->left;
        }
        else if(x > current_node->value){
            current_node = current_node->right;
        }
    }
    return NULL;
}

Node* searchBST_recursive(int x, Node* current_node)
{
    if(current_node == NULL){
        return NULL;
    }
    else if(x == current_node->value){
        return current_node;
    }
    else if(x < current_node->value){
        return searchBST_recursive(x, current_node->left);
    }
    else if(x > current_node->value){
        return searchBST_recursive(x, current_node->right);
    }
}

void in_order_traversal(Node* node)
{
    if(node == NULL){
        return;
    }
    in_order_traversal(node->left);
    cout << node->value << " ";
    in_order_traversal(node->right);
}

Node* in_order_successor(Node* node)
{
    Node* successor = NULL;
    /// Node has a right child (or right subtree)
    if(node->right != NULL){
        successor = node->right;
        while(successor->left != NULL)
        {
            successor = successor->left;
        }
        return successor;
    }
    /// Node has no right child (or right subtree)
    else{
        Node* current_node = root;
        while(current_node != node)
        {
            if(node->value < current_node->value){
                successor = current_node;
                current_node = current_node->left;
            }
            else{
                current_node = current_node->right;
            }
        }
        return successor;
    }
}

void printTree(Node* root, int depth = 0) /// No need to understand this function
{                                         /// Use this to visualize your tree only
    if (root == NULL) return;

    printTree(root->right, depth + 1);   // right subtree first (will print on top)

    for (int i = 0; i < depth; i++) {
        cout << "    ";                  // indentation per depth level
    }
    cout << root->value << endl;

    printTree(root->left, depth + 1);    // left subtree last (will print on bottom)
}

int main()
{
    insertBST(5);
    insertBST(7);
    insertBST(2);
    insertBST(1);
    insertBST(3);
    insertBST(6);
    cout << endl << endl;
    cout << "The Tree:" << endl;
    printTree(root);

    deleteBST(2);

    cout << "Sorted Sequence: ";
    in_order_traversal(root);
    cout << endl << endl;
    cout << "The Tree:" << endl;
    printTree(root);
}
