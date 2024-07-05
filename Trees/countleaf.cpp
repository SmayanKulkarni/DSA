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

int countLeafNodes(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->children.size() == 0) {
        return 1;
    }
    int ans = 0;
    for (size_t i = 0; i < root->children.size(); i++) {
        ans += countLeafNodes(root->children[i]);
    }
    return ans;
}

void countLeafNodesOtherWay(TreeNode<int>* root, int& ans) {
    if (root == nullptr) {
        return;
    }
    if (root->children.size() == 0) {
        ans++;
        return;
    }
    for (size_t i = 0; i < root->children.size(); i++) {
        countLeafNodesOtherWay(root->children[i], ans);
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    
    // Call the function to count leaf nodes and print the result
    int leafNodeCount = countLeafNodes(root);
    cout << "Number of leaf nodes: " << leafNodeCount << endl;
    
    int otherWayLeafCount = 0;
    countLeafNodesOtherWay(root, otherWayLeafCount);
    cout << "Number of leaf nodes (other way): " << otherWayLeafCount << endl;

    return 0;
}
