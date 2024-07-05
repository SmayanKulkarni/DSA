#include <iostream>
#include <vector>
#include<queue>
#include<stack>

using namespace std;
template<typename T>
class TreeNode{
    public: 
        T data;
        vector<TreeNode<T>*> children;
        TreeNode(T data)
        {
            this->data = data;         
        }
         
};


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter the data for root node: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* f = q.front();
        q.pop();
        int n;
        cout << "Enter the number of children of " << f->data << ": ";
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int childData;
            cout << "Enter the data for child " << i << ": ";
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            f->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

void depth(TreeNode<int>* root, int k)
{
    if(!root) return;
    if(k==0) {
        cout<<root->data<<endl;
    }

    for(int i =0;i<root->children.size();i++) {
        depth(root->children[i], k-1);
    }

}

int countLeafNodes(TreeNodeint root){
    if(root==NULL){   edge case
        return 0;
      }
      if(root-children.size()==0){
        return 1;
      }
      int ans = 0;
      for(int i=0;iroot-children.size();i++){
       ans +=  countLeafNodes(root-children[i]);
      }
      return ans;
}
void countLeafNodesOtherWay(TreeNodeint root, int &ans){
    if(root==NULL){   edge case
        return ;
    }
      if(root-children.size()==0){
         ans++;
         return;
      }
      for(int i=0;iroot-children.size();i++){
         countLeafNodesOtherWay(root-children[i],ans);
      }
}

int main()
{
    TreeNode<int>* root = takeInputLevelWise();
   
    depth(root, 2);
    
    return 0; 
}