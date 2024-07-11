class Solution {
    public:
    TreeNode* searchBST(TreeNode* root, int key) {
         TreeNode* empty;
        if(!root) return empty;
        if(root->val == key)
        {
            return root;
        }
        else if(key<root->val)
        {
            return searchBST(root->left, key);
        }
        else if(key<root->val)
        {
            return searchBST(root->right, key);
        }
    
}
};