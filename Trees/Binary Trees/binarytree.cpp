#include <iostream>
using namespace std;

template<typename T>
class BTnode
{
    T data;
    BTnode* left;
    BTnode* right;

    BTnode(){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTnode(){
            delete left;
            delete right;
        }
};

int main()
{
    BTnode<int>* root = new BTnode<int>(1);
    BTnode<int>* n1 = new BTnode<int>(2);
    BTnode<int>* n2 = new BTnode<int>(3);

    root->left = n1;
    root->right = n2;
    delete root;
    return 0;
}