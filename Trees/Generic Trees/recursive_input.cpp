#include <iostream>
#include <vector>

using namespace std;
template<typename T>
class TreeNode{
    public: 
        T data;
        vector<TreeNode<T>*> children;
        TreeNode(T data)
        {
            this->data = data;         
        }
         
};

void printTree(TreeNode<int>* root) 
{
    if(!root) return;
    cout<<root->data<<": ";
    for(int i = 0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i = 0;i<root->children.size();i++)
    {
        printTree(root->children[i]);
    }
}

TreeNode<int>* takeinput() // recursive
{
    int rootdata;
    cout<<"Enter the data for node: ";
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    int children;
    cout<<"How many children does "<<rootdata<< " have"<<endl;
    cin>>children;

    for(int i = 0;i<children;i++)
    {
        TreeNode<int>* child =takeinput();
        root->children.push_back(child);
    }
    return root;
}
int main()
{
    TreeNode<int>* root = takeinput();

    printTree(root);
    return 0; 
}