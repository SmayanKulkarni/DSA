#include <iostream>
#include <vector>
#include<queue>
#include<stack>

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

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter the data for root node: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* f = q.front();
        q.pop();
        int n;
        cout << "Enter the number of children of " << f->data << ": ";
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int childData;
            cout << "Enter the data for child " << i << ": ";
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            f->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}
void outputLevelWise(TreeNode<int>* root) 
{
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty())
    {
        TreeNode<int>* f = q.front();
        q.pop();
       cout<<f->data<<": ";
       for(int i = 0; i<f->children.size(); i++)
       {
            cout<<f->children[i]->data<<", ";
       }
       cout<<endl;
       for(int i =0;i<f->children.size(); i++)
       {
            q.push(f->children[i]);
       }
    }
   

}
int main()
{
    TreeNode<int>* root = takeInputLevelWise();
    outputLevelWise(root);
    // printTree(root);
    return 0; 
}