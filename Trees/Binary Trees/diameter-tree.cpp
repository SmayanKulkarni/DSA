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



//better approach 

class Solution {
public:

    pair<int,int> hd(TreeNode* root)
    {
        if(!root){
            pair<int,int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }
        
        pair<int, int> leftans = hd(root->left);
        pair<int, int> rightans = hd(root->right);

        int lh = leftans.first;
        int ld = leftans.second;
        int rh = rightans.first;
        int rd = rightans.second;

        int height = 1 + max(lh, rh);
        int diameter = max(lh + rh, max(ld,rd));
        pair<int,int> p ;
            p.first= height;
            p.second = diameter;
            return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int, int> p = hd(root);
        return p.second;
    }
};