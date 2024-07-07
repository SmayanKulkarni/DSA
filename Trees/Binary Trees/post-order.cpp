class Solution {
public:
    /**
     * Performs a postorder traversal of the binary tree and stores the node values in the given vector.
     * 
     * Postorder traversal visits the left subtree, then the right subtree, and finally the current node.
     * 
     *          1
     *         / \
     *        2   3
     *       / \   \
     *      4   5   6
     * 
     * Postorder traversal order: [4, 5, 2, 6, 3, 1]
*/
    void postorder(TreeNode* root, vector<int> &ans) {
        if (!root) return;
        
        postorder(root->left, ans);  // Visit left subtree
        postorder(root->right, ans); // Visit right subtree
        ans.push_back(root->val);   // Visit current node
    }

    /**
     * Returns a vector containing the node values of the binary tree in postorder traversal order.
     * 
     * Example:
     * Input: [1, 2, 3, 4, 5, 6]
     * Output: [4, 5, 2, 6, 3, 1]
 */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};