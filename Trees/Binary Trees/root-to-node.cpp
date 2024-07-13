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

BTnode<int> *takeinputLevelWise()
{
    int data;
    cout << "Enter data: ";
    cin >> data;

    if (data == -1)
        return NULL;
    queue<BTnode<int> *> q;
    BTnode<int> *root = new BTnode<int>(data);
    q.push(root);

    while (!q.empty())
    {
        BTnode<int> *temp = q.front();
        q.pop();

        cout << "Enter left child of " << temp->data << ": ";
        int left_child;
        cin >> left_child;
        if (left_child != -1)
        {
            temp->left = new BTnode<int>(left_child);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << ": ";
        int right_child;
        cin >> right_child;
        if (right_child != -1)
        {
            temp->right = new BTnode<int>(right_child);
            q.push(temp->right);
        }
    }

    return root;
}
void printtree(BTnode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << endl;
    if (root->left)
    {
        cout << "L: " << root->left->data;
    }
    if (root->right)
    {
        cout << "R: " << root->right->data;
    }
    printtree(root->left);
    printtree(root->right);
}

bool getpath(BTnode<int> *root, int k, vector<int> &ans)
{
    if (!root)
        return false;
    ans.push_back(root->data);
    if (root->data == k)
    {
        return true;
    }

    bool leftcheck = getpath(root->left, k, ans);
    bool rightcheck = getpath(root->right, k, ans);

    if( (leftcheck || rightcheck)) return true;

    ans.pop_back();
    return false;
}
int main()
{
    BTnode<int> *root = takeinputLevelWise();
    printtree(root);
    int k = 5;
    vector<int> ans;
    if (getpath(root, k, ans))
    {
        cout << "Path exists: ";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    }
    else
    {
        cout << "Path does not exist.";
    }
    delete root;
    return 0;
}