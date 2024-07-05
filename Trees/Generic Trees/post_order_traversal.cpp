#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data) {
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

void preorderTraversal(TreeNode<int> * root)
{
    if(!root) return;

    
    for(int i = 0;i<root->children.size(); i++)
    {
        preorderTraversal(root->children[i]);
    }
    cout<<root->data<<" ";
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    preorderTraversal(root);
    
    
    return 0;
}
