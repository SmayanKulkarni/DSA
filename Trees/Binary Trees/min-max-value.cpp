#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BTnode
{
public:
    T data;
    BTnode *left;
    BTnode *right;

    BTnode(T data)
    {

        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTnode()
    {
        delete left;
        delete right;
    }
};

BTnode<int>* takeinputLevelWise()
{
    int data;
    cout<<"Enter data: ";
    cin>>data;

    if(data==-1) return NULL;
    queue<BTnode<int>*> q;
    BTnode<int>* root = new BTnode<int>(data);
    q.push(root);
    
    while(!q.empty())
    {
        BTnode<int>* temp = q.front();
        q.pop();

        cout<<"Enter left child of "<<temp->data<<": ";
        int left_child;
        cin>>left_child;
        if(left_child!=-1)
        {
            temp->left = new BTnode<int>(left_child);
            q.push(temp->left);
        }

        cout<<"Enter right child of "<<temp->data<<": ";
        int right_child;
        cin>>right_child;
        if(right_child!=-1)
        {
            temp->right = new BTnode<int>(right_child);
            q.push(temp->right);
        }
    }

    return root;

}
void printtree(BTnode<int> *root)
{
    if(root == NULL) return;
    cout<<root->data<<endl;
    if(root->left)
    {
        cout<<"L: "<<root->left->data;
    }
    if(root->right)
    {
        cout<<"R: "<<root->right->data;
    }
        printtree(root->left);
        printtree(root->right);
    
}

int minvalue(BTnode<int>* root)
{
    if(!root) return __INT_MAX__;
    int ans = root->data;
    int leftmin = minvalue(root->left);
    int rightmin = minvalue(root->right);

    return min(root->data, min(leftmin, rightmin));

}

int maxvalue(BTnode<int>* root)
{
    if(!root) return INT_MIN;
    int ans = root->data;
    int leftmin = minvalue(root->left);
    int rightmin = minvalue(root->right);

    return max(root->data, max(leftmin, rightmin));

}

void minval(BTnode<int> *root, int &ans){
    if(root==NULL) return;
    int ans = min(root->data, ans);;
    minval(root->left, ans);
    minval(root->right, ans);
    
}

void maxval(BTnode<int> *root, int &ans){
    if(root==NULL) return;
    int ans = max(ans,root->data);
    maxval(root->left, ans);
    maxval(root->right, ans);
    
}
int main()
{
    BTnode<int>* root = takeinputLevelWise();
    printtree(root);
    cout<<endl;
    int ans = minvalue(root);
    cout<<ans<<endl;
    return 0;
}