class Solution {
public:

    int height(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + max(height(root->right), height(root->left));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        int opt1 = lh + rh;
        int opt2 = diameterOfBinaryTree(root->left);
        int opt3 = diameterOfBinaryTree(root->right);
        return max(opt1, max(opt2, opt3));
    }
};