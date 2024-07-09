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

BTnode<int>* takeinput()
{
    int data;
    cout<<"Enter data: ";
    cin>>data;

    if(data==-1) return NULL;
    BTnode<int>* root = new BTnode<int>(data);
    BTnode<int>* leftchild = takeinput();
    BTnode<int>* rightchild = takeinput();
    root->left = leftchild;
    root->right = rightchild;

    return root;

}
void printtree(BTnode<int> *root)
{
    if(root == NULL) return;
    cout<<root->data<<endl;
    if(root->left)
    {
        cout<<"L: "<<root->left->data;
    }
    if(root->right)
    {
        cout<<"R: "<<root->right->data;
    }
        printtree(root->left);
        printtree(root->right);
    
}
int main()
{
    BTnode<int>* root = takeinput();
    printtree(root);
    delete root;
    return 0;
}