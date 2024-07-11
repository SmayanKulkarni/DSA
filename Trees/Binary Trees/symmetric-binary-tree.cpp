class Solution {
public:
    bool helper(TreeNode* leftchild, TreeNode* rightchild) {
        if (leftchild == NULL && rightchild != NULL)
            return false;
        if (leftchild != NULL && rightchild == NULL)
            return false;
        
        if (leftchild == NULL && rightchild == NULL)
            return true;
            if (leftchild->val != rightchild->val)
            return false;

        return helper(leftchild->left, rightchild->right) && helper(leftchild->right,rightchild->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left, root->right);
    }
};