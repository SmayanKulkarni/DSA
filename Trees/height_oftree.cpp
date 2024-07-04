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

int height(TreeNode<int>* root)
{
    if(!root) return 0;
    int mx = 0;
    for(int i =0;i<root->children.size();i++)  
    {
        mx = max(mx, height(root->children[i]));
    }
    return mx+1;
}

int main()
{
    TreeNode<int>* root = takeInputLevelWise();
   
    int ans = height(root);
    cout<<endl;
    cout<<ans<<endl;
    // printTree(root);
    return 0; 
}