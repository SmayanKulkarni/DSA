class BTnode
{
    T data;
    BTnode *left;
    BTnode *right;

    BTnode(T data)
    {
    public:
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
