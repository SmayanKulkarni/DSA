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
        left = nullptr;
        right = nullptr;
    }
    ~BTNode()
    {
        delete left;
        delete right;
    }
};

class Pair
{
public:
    BTNode<int> *head;
    BTNode<int> *tail;
};

class BST
{
    BTNode<int> *root;

    void printTree(BTNode<int> *root)
    {
        if (root == nullptr)
        {
            return;
        }

        cout << root->data << ": ";
        if (root->left != nullptr)
        {
            cout << "L" << root->left->data;
        }

        if (root->right != nullptr)
        {
            cout << "R" << root->right->data;
        }
        cout << endl;

        printTree(root->left);
        printTree(root->right);
    }

    bool hasData(BTNode<int> *node, int data)
    {
        if (node == nullptr)
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

    BTNode<int> *deletedata(BTNode<int> *node, int data)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (data < node->data)
        {
            node->left = deletedata(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = deletedata(node->right, data);
        }
        else
        {
            if (node->right == nullptr && node->left == nullptr)
            {
                delete node;
                return nullptr;
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
                node->data = minNode->data;
                node->right = deletedata(node->right, minNode->data);
            }
        }
        return node;
    }

    Pair convertLL(BTNode<int>* root)
    {
        if (root == nullptr)
        {
            return {nullptr, nullptr};
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            Pair p;
            p.head = root;
            p.tail = root;
            return p;
        }
        else if (root->left != nullptr && root->right == nullptr)
        {
            Pair leftLL = convertLL(root->left);
            leftLL.tail->right = root;
            Pair ans;
            ans.head = leftLL.head;
            ans.tail = root;
            return ans;
        }
        else if (root->left == nullptr && root->right != nullptr)
        {
            Pair rightLL = convertLL(root->right);
            root->right = rightLL.head;
            Pair ans;
            ans.head = root;
            ans.tail = rightLL.tail;
            return ans;
        }
        else
        {
            Pair leftLL = convertLL(root->left);
            Pair rightLL = convertLL(root->right);
            leftLL.tail->right = root;
            root->right = rightLL.head;
            Pair ans;
            ans.head = leftLL.head;
            ans.tail = rightLL.tail;
            return ans;
        }
    }

public:
    BST()
    {
        root = nullptr;
    }
    ~BST()
    {
        delete root;
    }

    void deleteData(int data) // O(h)
    {
        root = deletedata(root, data);
    }
    void insert(int data) // O(h)
    {
        root = insert(root, data);
    }
    bool hasData(int data)
    {
        return hasData(root, data);
    }
    void print() // O(h)
    {
        printTree(root);
    }
    BTNode<int>* convertLL()
    {
        Pair p = convertLL(root);
        return p.head;
    }
};

int main()
{
    BST b;
    b.insert(10);
    b.insert(20);
    b.insert(30);
    b.insert(40);
    b.insert(50);
    b.insert(60);

    BTNode<int>* head = b.convertLL();
    BTNode<int>* temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        BTNode<int>* next = temp->right;
        temp->right = nullptr;
        temp = next;
    }
    return 0;
}
