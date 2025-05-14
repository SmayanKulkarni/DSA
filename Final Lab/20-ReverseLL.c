#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    struct node *next;
    int data;
};

struct node *stack[100];
int top = -1;

void push(struct node *data)
{

    stack[++top] = data;
}

struct node *pop()
{
    struct node *val = stack[top--];
    return val;
}

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

struct node *ReverseLL(struct node *head)
{
    struct node *dummy = (struct node *)malloc(sizeof(struct node));
    struct node *rev = dummy;
    struct node *temp = head;
    while (temp != NULL)
    {
        push(temp);
        temp = temp->next;
    }

    while (!isEmpty())
    {
        rev->next = pop();
        rev = rev->next;
    }
    rev->next = NULL;
    return dummy->next;
}

struct node *InsertEnd(struct node *head, int data)
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        struct node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = NULL;
    }
    return head;
}

void print(struct node *head)
{
    printf("\n");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{

    struct node *head = NULL;
    int n;
    printf("Enter size of list: \n");
    scanf("%d", &n);
    printf("Insert List: \n");
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        head = InsertEnd(head, temp);
    }

    struct node *rev1 = ReverseLL(head);

    print(rev1);

    return 0;
}
