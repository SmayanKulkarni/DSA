class Solution {
public:
    /**
     * Performs a preorder traversal of the binary tree and stores the node values in a vector.
     * 
     * The preorder traversal visits the current node, then the left subtree, and finally the right subtree.
     */
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
     * Input: [1, 2, 3, 4, 5, 6, 7]
     * Output: [1, 2, 4, 5, 3, 6, 7]
     * 
     * The binary tree:
     *       1
     *     /   \
     *    2     3
     *   / \   / \
     *  4   5 6   7
     * 
     * The preorder traversal visits the nodes in the following order:
     * 1, 2, 4, 5, 3, 6, 7
     */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};