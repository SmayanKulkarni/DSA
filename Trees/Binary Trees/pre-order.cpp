class Solution {
public:
    void preorder(TreeNode* root, vector<int> &ans) {
        if (!root) return;
        ans.push_back(root->val); // Visit the current node
        preorder(root->left, ans); // Traverse the left subtree
        preorder(root->right, ans); // Traverse the right subtree
    }
    /**
     * Returns a vector containing the node values of the binary tree in preorder traversal order.
     * 
     * Example:
     * Input: root = [1,2,3]
     * Output: [1,2,3]*/

    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> a;
        preorder(root, a);
        return a;
    }
};