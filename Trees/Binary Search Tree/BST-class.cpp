#include <iostream>
using namespace std;

template <typename T>
class BTNode
{
public:
    T data;
    BTNode *left;
    BTNode *right;

    BTNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTNode()
    {
        delete left;
        delete right;
    }
};
class BST
{
    BTNode<int> *root;

    void printTree(BTNode<int> *root)
    {
        if (root == NULL)
        { /// base case
            return;
        }

        cout << root->data << ": ";
        if (root->left != NULL)
        {
            cout << "L" << root->left->data;
        }

        if (root->right != NULL)
        {
            cout << "R" << root->right->data;
        }
        cout << endl;

        printTree(root->left);
        printTree(root->right);
    }
    bool hasData(BTNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }

        if (node->data > data)
        {
            return hasData(node->left, data);
        }
        else
        {
            return hasData(node->right, data);
        }
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    void deleteData(int data)
    {
    }
    void insert(int data)
    {
    }
    bool hasData(int data)
    {
        return hasData(root, data);
    }
    void print()
    {
        printTree(root);
    }
};
int main()
{

    return 0;
}