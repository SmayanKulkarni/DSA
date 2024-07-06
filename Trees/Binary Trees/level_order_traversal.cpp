#include <iostream>
#include <queue>
using namespace std;

/**
 * A template class to represent a node in a binary tree.
 *
 * @tparam T The type of data stored in the node.
 */
template <typename T>
class BTnode
{
public:
    T data;
    BTnode *left;
    BTnode *right;

    /**
     * Constructor to create a new node with the given data.
     *
     * @param data The data to be stored in the node.
     */
    BTnode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    /**
     * Destructor to delete the node and its children.
     */
    ~BTnode()
    {
        delete left;
        delete right;
    }
};

/**
 * A function to take input for a binary tree level-wise.
 *
 * The function prompts the user to enter the data for each node, and its left and right children.
 * If the user enters -1, it is considered as a null node.
 *
 * @return The root node of the constructed binary tree.
 */
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

/**
 * A function to print the binary tree in a pre-order traversal.
 *
 * The function prints the data of each node, followed by its left and right children.
 *
 * @param root The root node of the binary tree.
 */
void printtree(BTnode<int> *root)
{
    if (!root)
        return;
    cout << root->data << endl;
    if (!root->left)
    {
        cout << "L: " << root->left->data;
    }
    if (!root->right)
    {
        cout << "R: " << root->right->data;
    }
    printtree(root->left);
    printtree(root->right);
}

/**
 * A function to print the binary tree in a level-order traversal.
 *
 * The function uses a queue to print the nodes level by level.
 *
 * @param root The root node of the binary tree.
 */
void printLevelOrderTraversal(BTnode<int> *root)
{
    queue<BTnode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BTnode<int> *temp = q.front();
        cout << temp->data << " " << endl;
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    // Example usage:
    // Create a binary tree with the following structure:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    BTnode<int> *root = takeinputLevelWise();
    printLevelOrderTraversal(root);
    delete root;
    return 0;
}

// In this code, q.push is used instead of recursion for the printLevelOrderTraversal function because it allows for a level-order traversal of the binary tree.

// Level-order traversal means visiting all nodes at a given level before moving on to the next level. This is different from pre-order, in-order, and post-order traversals, which visit nodes in a specific order based on their position in the tree.

// Recursion is not well-suited for level-order traversal because it would require recursively calling the function for each node, which would lead to a depth-first traversal (i.e., visiting as far as possible along each branch before backtracking).

// Using a queue (q) allows the function to keep track of nodes at each level and process them in order. Here's how it works:

// The root node is added to the queue.
// The function enters a loop that continues until the queue is empty.
// In each iteration, the front node is removed from the queue and its value is printed.
// The left and right children of the current node are added to the queue (if they exist).
// The loop repeats until the queue is empty, which means all nodes have been processed.
// By using a queue, the function can efficiently traverse the tree level by level, without relying on recursion.

// In contrast, if recursion were used, the function would recursively call itself for each node, leading to a depth-first traversal. This would not allow for a level-order traversal, as the function would not be able to keep track of nodes at each level.

