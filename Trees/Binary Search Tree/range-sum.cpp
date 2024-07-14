class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root)
            return 0;

        int sum = 0;
        
        if(root->val >= low && root->val<=high)
        {
            sum = sum + root->val;
        }
        if(root->val > high)
        {
            sum+= rangeSumBST(root->left, low, high);
        }
        else if(root->val < low) 
        {
            sum = sum + rangeSumBST(root->right, low, high);
        }
        else {
            sum = sum + rangeSumBST(root->right, low, high) + rangeSumBST(root->left, low, high);
        }
        return sum;
    }
};