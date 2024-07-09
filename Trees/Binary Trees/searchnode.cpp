TreeNode* searchNode(BTNode<int>* root, int key){
   if(root==NULL){
    return false;
   }
   if(root->data == key){
    return true;
   }

   return (searchNode(root->left,key) || searchNode(root->right,key));
}