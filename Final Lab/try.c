#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    struct node *next;
    int data;
};

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

struct node *MergeLL(struct node *l1, struct node *l2)
{
    struct node *t1 = l1;
    struct node *t2 = l2;
    struct node *merge = (struct node*)malloc(sizeof(struct node));
    struct node *final = merge;

    while(t1 && t2){

        if(t1->data < t2->data){
            final->next = t1;
            t1 = t1->next;
        }
        else{
            final->next = t2;
            t2 = t2->next;
        }
        final = final->next;
    }
    if(t1) {
        final->next = t1;
    }
    else{
        final->next =t2;
    }

    return merge->next;

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
    int n1, n2;
    struct node *l1 = NULL;
    struct node *l2 = NULL;
    struct node *l3 = NULL;
    printf("Enter size of list 1: \n");
    scanf("%d", &n1);
    printf("Enter size of list 2: \n");
    scanf("%d", &n2);
    printf("Insert List 1: \n");
    for (int i = 0; i < n1; i++)
    {
        int temp;
        scanf("%d", &temp);
        l1 = InsertEnd(l1, temp);
    }
    printf("Insert List 2: \n");
    for (int i = 0; i < n2; i++)
    {
        int temp;
        scanf("%d", &temp);
        l2 = InsertEnd(l2, temp);
    }

    l3 = MergeLL(l1, l2);
    print(l3);
}
