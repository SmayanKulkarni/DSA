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

    struct node *newnode = (struct node*) malloc(sizeof(struct node));
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
    if (l1 == NULL)
    {
        return l2;
    }
    else if (l2 == NULL)
    {
        return l1;
    }
    struct node *merge = (struct node*) malloc(sizeof(struct node));
    struct node *p = NULL;
    struct node *q = NULL;
    struct node *r = NULL;
    merge->next = NULL;
    p = l1;
    q = l2;
    r = merge;

    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            r->next = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            q = q->next;
        }
        r =r->next;
    }

    if(p!=NULL){
        r->next = p;
    }
    if(q!=NULL){
        r->next = q;    
    }
    return merge->next;
}

void print(struct node *head) {
    printf("\n");
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int n1, n2;
    struct node *l1 = (struct node*)malloc(sizeof(struct node));
    struct node *l2 = (struct node*)malloc(sizeof(struct node));
    struct node *l3 = (struct node*)malloc(sizeof(struct node));
    printf("Enter size of list 1: \n");
    scanf("%d", &n1);
    printf("Enter size of list 2: \n");
    scanf("%d", &n2);
    printf("Insert List 1: \n");
    for(int i =0;i<n1;i++){
        int temp;
        scanf("%d", &temp);
        l1 = InsertEnd(l1,temp);
    }
    printf("Insert List 2: \n");
    for(int i =0;i<n2;i++){
        int temp;
        scanf("%d", &temp);
        l1 = InsertEnd(l1,temp);
    }

    l3 = MergeLL(l1,l2);
    print(l3);


}
