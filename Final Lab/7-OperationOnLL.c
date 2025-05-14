#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data;
};

struct Node *InsertBegin(struct Node *head, int val)
{
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = val;
        if (head == NULL)
        {
            head = new_node;
            head->next = NULL;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
    return head;
}

struct Node *DeleteBegin(struct Node *head)
{
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

struct Node *InsertEnd(struct Node *head, int val)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    new_node->data = val;
    if (head == NULL)
    {
        head = new_node;
        head->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    }
    return head;
}

struct Node *DeleteEnd(struct Node *head)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    return head;
}

struct Node *InsertAfter(struct Node *head, int val, int key)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = val;
    if (head == NULL)
    {
        head = new_node;
        head->next = NULL;
    }
    else
    {
        struct Node *temp = head;
        while (temp->data != key)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    return head;
}

struct Node *InsertBefore(struct Node *head, int val, int key)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = val;
    if (head == NULL)
    {
        head = new_node;
        head->next = NULL;
    }
    else if(head->data == key){
        new_node->next = head;
        head = new_node;    
    }
    else
    {
        struct Node *temp = head;
        struct Node *prev = NULL;

        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Key not found!\n");
            free(new_node);
            return head;
        }
        prev->next = new_node;
        new_node->next = temp;
    }
    return head;
}

struct Node *DeleteSpecific(struct Node *head, int key)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    if (head == NULL)
    {
        printf("Underflow");
        return NULL;
    }
    else if(head->data == key){
        struct Node *newHead = head->next;
        free(head);
        return newHead;
    }
    else
    {
        while (temp!= NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp==NULL){
            printf("Node not found!\n");
            return head;
        }
        prev->next = temp->next;
        free(temp);
    }
    return head;
}

void SearchNode(struct Node *head, int key)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Underflow");
    }
    else
    {
        while (temp->data != key && temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            printf("The node is not found.");
            return; 
        }
        else{
            printf("The node is found");
        }
    }
    printf("The Node is not found.");
    return;
}

void print(struct Node *head)
{
    printf("\n");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    head = InsertBegin(head, 10);
    head = InsertBegin(head, 20);
    head = InsertBegin(head, 20);
    head = InsertBegin(head, 20);
    head = InsertBegin(head, 20);
    head = InsertBegin(head, 30);
    head = InsertEnd(head, 40);
    head = InsertEnd(head, 40);
    head = InsertEnd(head, 40);
    head = InsertEnd(head, 40);
    head = InsertEnd(head, 40);
    head = InsertEnd(head, 50);
    head = InsertAfter(head, 50, 20);
    head = InsertAfter(head, 50, 20);
    head = InsertAfter(head, 50, 20);
    head = InsertBefore(head, 70, 20);
    head = DeleteBegin(head);
    head = DeleteBegin(head);
    head = DeleteBegin(head);
    head = DeleteBegin(head);
    head = DeleteEnd(head);
    head = DeleteSpecific(head, 50);
    head = DeleteSpecific(head, 20);
    head = DeleteSpecific(head, 10);
    head = DeleteSpecific(head, 40);
    head = DeleteSpecific(head, 40);
    head = DeleteSpecific(head, 40);
    head = DeleteSpecific(head, 40);
    SearchNode(head, 12);
    print(head);

    return 0;
}
