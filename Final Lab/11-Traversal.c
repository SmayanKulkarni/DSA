#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

InOrder(struct node *root)
{

    if (root == NULL)
        return;

    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

void PreOrder(struct node *root)
{

    if (root == NULL)
        return;
    printf("%d ", root->data);
    PreOrder(root->left);
    InOrder(root->right);
}

void PostOrder(struct node *root)
{

    if (root == NULL)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}

struct node *newNode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void LevelOrder(struct node *root)
{
    if (root == NULL)
        return;

    struct node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        struct node *current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

struct node *createTree()
{
    int n;
    struct node *newnode = newNode(n);
    printf("\nEnter the data: ");
    scanf("%d", &n);
    if (n == -1)
    {
        return NULL;
    }
    newnode->data = n;
    printf("Enter left child of %d", n);
    newnode->left = createTree();
    printf("Enter right child of %d", n);
    newnode->right = createTree();
    return newnode;
}

void main()
{

    struct node *root = NULL;
    root = createTree();
    printf("Inorder: ");
    InOrder(root);
    printf("\nPreorder: ");
    PreOrder(root);
    printf("\nPostorder: ");
    PostOrder(root);
    printf("\nLevelorder: ");
    LevelOrder(root);
    
}