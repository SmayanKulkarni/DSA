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
            return hasData(node->right, data); // yes
        }
    }

    BTNode<int> *insert(BTNode<int> *node, int data)
    {
        if (node == nullptr)
        {
            BTNode<int> *newNode = new BTNode<int>(data);
            return newNode;
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }

        return node;
    }
        BTNode<int> *deletedata(BTNode<int> * node, int data)
        {
            if (node == nullptr)
                return nullptr;

            if (data < node->data)
            {
                node->left = deletedata(node, data);
            }
            else if (data > node->data)
            {
                node->right = deletedata(node, data);
            }
            else
            {
                if (node->right == nullptr && node->left == nullptr)
                {
                    delete node;
                    node = nullptr;
                    return node;
                }
                else if (node->right == nullptr)
                {
                    BTNode<int> *temp = node->left;
                    node->left = nullptr;
                    delete node;
                    return temp;
                }
                else if (node->left == nullptr)
                {
                    BTNode<int> *temp = node->right;
                    node->right = nullptr;
                    delete node;
                    return temp;
                }
                else
                {
                    BTNode<int> *minNode = node->right;
                    while (minNode->left)
                    {
                        minNode = minNode->left;
                    }
                    int mindata = minNode->data;
                    node->data = mindata;
                    node->right = deletedata(node->right, mindata);
                }
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
            root = insert(root, data);
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
