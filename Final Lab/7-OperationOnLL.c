#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    int data;
};

struct Node* InsertBegin(struct Node *head, int val) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    if(head==NULL) {
        head = new_node;
        head->next = NULL;
    } 
    else{
        new_node->next = head;
        head = new_node;
    }   
    return head;
}

struct Node* DeleteBegin(struct Node *head) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(head==NULL) {
        printf("Underflow");
    } 
    else{
        temp = head;
        head = head->next;
        free(temp);
    }   
    return head;
}

struct Node* InsertEnd(struct Node *head, int val) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;
    new_node->data = val;
    if(head==NULL) {
        head = new_node;
        head->next = NULL;
    }      
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;

}

struct Node* DeleteEnd(struct Node *head) {
    struct Node *temp = head;
    struct Node *prev = NULL;
    
    if(head==NULL) {
        printf("Underflow");
    }      
    else{
        while(temp->next!=NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        
    }
    return head;

}

struct Node* InsertAfter(struct Node *head, int val, int key) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;
    new_node->data = val;
    if(head==NULL) {
        head = new_node;
        head->next = NULL;  
    }      
    else{
        while(temp->data!=key){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
    return head;

}

struct Node* InsertBefore(struct Node *head, int val, int key) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;
    struct Node *prev = NULL;
    new_node->data = val;
    if(head==NULL) {
        head = new_node;
        head->next = NULL;  
    }      
    else{
        while(temp->data!=key){
            prev = temp;
            temp = temp->next;
        }
        prev->next = new_node;
        new_node->next = temp;
    }
    return head;

}


struct Node* DeleteSpecific(struct Node *head, int key) {
    struct Node *temp = head;
    struct Node *prev = NULL;
    if(head==NULL) {
        printf("Underflow"); 
    }      
    else{
        while(temp->data!=key){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }
    return head;

}

void print(struct Node *head) {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;  

    head = InsertBegin(head, 10); 
    head = InsertBegin(head, 20); 
    head = InsertBegin(head, 30);
    head = InsertEnd(head, 40);
    head = InsertEnd(head, 50);
    head = InsertAfter(head, 50, 20);
    head = InsertBefore(head, 70, 20);
    head = DeleteBegin(head);
    head = DeleteEnd(head);
    head = DeleteSpecific(head, 50);

    print(head);  

    return 0;
}
