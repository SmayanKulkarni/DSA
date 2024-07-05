#include <iostream>
#include <vector>
#include<queue>
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

TreeNode<int>* takeinputLevelWise() // recursive
{
    int rootdata;
    cout<<"Enter the data for node: ";
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty())
    {
        
        TreeNode<int>* f = q.front();
        q.pop();
        int n;
        int childData;
        cout<<"Enter the number of children of"<<f->data<<endl;
        cin>>n;

        for(int i = 1;i<=n;i++)
        {
            int childdata;
            cout<<"Enter the data for child "<<i+1<<": ";
            cin>>childdata;
            TreeNode<int>* child = new TreeNode<int>(childData);
            f->children.push_back(child);
            q.push(child);
        }

    }
    return root;
}
int main()
{
    TreeNode<int>* root = takeinputLevelWise();

    printTree(root);
    return 0; 
}