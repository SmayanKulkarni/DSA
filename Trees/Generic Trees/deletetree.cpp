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
    ~TreeNode()
    {
        for(int i = 0;i<children.size(); i++)
        {
            delete children[i];
        }
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

void deleteTree(TreeNode<int> * root)
{
    if(!root) return;

    for(int i = 0;i<root->children.size(); i++)
    {
        delete(root->children[i]);
    }
    delete root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    deleteTree(root);

    delete root; // will only work with a destructor initialized 
    
    
    return 0;
}
