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
     * Input: root = [1,2,3,4,5,6,7]
     * Output: [1,2,4,5,3,6,7]
     * 
     * The binary tree is:
     *            1
     *           / \
     *          2   3
     *         / \   \
     *        4   5   6
     *           \
     *            7
     * 
     * The preorder traversal visits the nodes in the order: 1, 2, 4, 5, 7, 3, 6.
 */
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> a;
        preorder(root, a);
        return a;
    }
};