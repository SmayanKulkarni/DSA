#include <iostream>
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

void printtree(BTnode<int> *root)
{
    if(!root) return;
    cout<<root->data<<endl;
        printtree(root->left);
        printtree(root->right);
    
}
int main()
{
    BTnode<int>* root = new BTnode<int>(1);
    BTnode<int>* n1 = new BTnode<int>(2);
    BTnode<int>* n2 = new BTnode<int>(3);

    root->left = n1;
    root->right = n2;
    printtree(root);
    delete root;
    return 0;
}