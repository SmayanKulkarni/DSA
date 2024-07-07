class Solution {
public:
    /**
     * Performs an in-order traversal of the binary tree and stores the node values in a vector.
     * 
     * In-order traversal visits the left subtree, the current node, and then the right subtree.
     * 
     * Example:
     * 
     *             4
     *            / \
     *           2   6
     *          / \   \
     *         1   3   5
     * 
     * The in-order traversal of this tree would be: [1, 2, 3, 4, 5, 6]
   */
    void inorder(TreeNode* root, vector<int> &ans)
    {
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    /**
     * Returns a vector of node values in in-order traversal order
*/
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};