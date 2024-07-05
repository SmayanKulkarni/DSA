#include <iostream>
#include <vector>
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

    vector<TreeNode<int>*> pendingNodes;
    pendingNodes.push_back(root);
    int nodeCount = 0;
    while (nodeCount < pendingNodes.size()) {
        TreeNode<int>* front = pendingNodes[nodeCount];
        nodeCount++;

        int numChildren;
        cout << "Enter the number of children of " << front->data << ": ";
        cin >> numChildren;

        for (int i = 0; i < numChildren; i++) {
            int childData;
            cout << "Enter the data for child " << i + 1 << " of " << front->data << ": ";
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push_back(child);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    // Further code to use the tree
    return 0;
}
