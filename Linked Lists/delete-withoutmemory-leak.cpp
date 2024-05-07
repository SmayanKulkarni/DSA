#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;

        Node(int data)
        {
            this->data= data;
            next=NULL;
        }
};

void print(Node *head)
{
    Node *temp = head;

    while(temp!=NULL) {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

Node* takeinput()
{
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL) // 1st Node
        {
            head = n;
            tail = n;
        }
        else // Consecutive Nodes
        {
            tail->next = n; // Connect the new node to the current tail
            tail = n;       // Update the tail to the new node
        }
        cin >> data;
    }
    return head;
}


int length(Node *head)
{
    int count=0;
    Node *temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
   return count; 

}

Node* insertatith(Node *head, int i, int data) {
    if(i<0)
    {
        return head;
    }
    if(i==0)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
        return head;
    }
     Node *copyhead = head;
    int count =1;
    while (count<=i-1 && head!=NULL)    
    {
        head = head->next;
        count++;
    }
    if(head)
    {
        Node *n = new Node(data);
        n->next = head->next;
        head->next = n;
        return copyhead;
    }
    return copyhead;
    
}

void insertnode(Node *head, int i, int input)
{
    int len = length(head);
    if (i > len) {
        cout << "Index out of range" << endl;
        return;
    }
    else 
    {
        Node *newNode = new Node(input); // Create the new node to be inserted

        if (i == 0) { // If inserting at the beginning
            newNode->next = head; // Connect the new node to the current head
            head = newNode; // Update the head to point to the new node
            return;
        }

        int j = 0;
        Node *temp = head;
        while (temp != NULL) {
            if (j == i - 1) { // If the next node is the position to insert
                newNode->next = temp->next; // Connect the new node to the next node
                temp->next = newNode; // Connect the current node to the new node
                return;
            }
            temp = temp->next;
            j++;
        }
    }
}


Node* deleteithNode(Node* head, int i)
{
    if(i<0)
    {
        return head;
    }
    if(i==0 &&head)
    {
        Node* newHead = head->next; 
        head->next=NULL;
        delete head;
        return newHead;
    }

    Node* curr = head;
    int count=0;
    while(count<=i-1 &&curr!=NULL)
    {
        curr=curr->next;
        count++;
    }
    if(curr && curr->next)
    {
        Node *temp = curr->next;
        curr->next = curr->next->next;
        temp->next=NULL;
        delete temp;
        return head;
    }
    return head;
}



int main()
{
    Node *head = takeinput();

    
    deleteithNode(head,4);
    // cout<<length(head)<<endl;
    // insertnode(head, 3, 20);
    print(head);
    //  print_itnode(head, 3);
    //  printith_2(head, 3);
    return 0;
    

}
