#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BTnode
{
public:
    T data;
    BTnode *left;
    BTnode *right;

    BTnode(T data)
    {

        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTnode()
    {
        delete left;
        delete right;
    }
};

BTnode<int> *takeinputLevelWise()
{
    int data;
    cout << "Enter data: ";
    cin >> data;

    if (data == -1)
        return NULL;
    queue<BTnode<int> *> q;
    BTnode<int> *root = new BTnode<int>(data);
    q.push(root);

    while (!q.empty())
    {
        BTnode<int> *temp = q.front();
        q.pop();

        cout << "Enter left child of " << temp->data << ": ";
        int left_child;
        cin >> left_child;
        if (left_child != -1)
        {
            temp->left = new BTnode<int>(left_child);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << ": ";
        int right_child;
        cin >> right_child;
        if (right_child != -1)
        {
            temp->right = new BTnode<int>(right_child);
            q.push(temp->right);
        }
    }

    return root;
}
void printtree(BTnode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << endl;
    if (root->left)
    {
        cout << "L: " << root->left->data;
    }
    if (root->right)
    {
        cout << "R: " << root->right->data;
    }
    printtree(root->left);
    printtree(root->right);
}

int minval(BTnode<int>* root)
{
    if(!root) return -1;
    while(root->left != nullptr )
    {
        root = root->left;
    }
    return root->data;
}
int maxval(BTnode<int>* root)
{
    if(!root) return -1;
    while(root->right != nullptr )
    {
        root = root->right;
    }
    return root->data;
}

int main()
{
    BTnode<int> *root = takeinputLevelWise();
    printtree(root);
    cout<<maxval(root)<<endl;
    delete root;
    return 0;
}