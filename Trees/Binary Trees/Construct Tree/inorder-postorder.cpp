class Solution {
public:
    TreeNode* buildTreehelper(vector<int>& inorder, vector<int>& postorder, int ins, int ine, int ps, int pe) {
        if (ins > ine || ps > pe) {
            return NULL;
        }
        int rootdata = postorder[pe];
        int ri = -1;
        for (int i = ins; i <= ine; i++) {
            if (inorder[i] == rootdata) {
                ri = i;
                break;
            }
        }

        int lis = ins;
        int lie = ri - 1;
        int lps = ps;
        int lpe = lps + lie - lis;

        int ris = ri + 1;
        int rie = ine;
        int rps = lpe + 1;
        int rpe = pe - 1;

        TreeNode* root = new TreeNode(rootdata);
        root->left = buildTreehelper(inorder, postorder, lis, lie, lps, lpe);
        root->right = buildTreehelper(inorder, postorder, ris, rie, rps, rpe);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return buildTreehelper(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};
