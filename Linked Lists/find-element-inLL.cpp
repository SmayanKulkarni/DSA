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
   if (head==NULL) return 0;
   
   return 1+ length(head->next);
}

bool search(Node *head, int data)
{
    Node* curr = head; // main
    while (curr!=NULL) 
    {
        if (curr->data==data) return true;
        curr = curr->next;
    }
    return false;
    
}
int main()
{
    Node *head = takeinput();

    
    // deleteithNode(head,4);
    // cout<<length(head)<<endl;
    cout<<search(head, 3)<<endl;
    // insertnode(head, 3, 20);
    print(head);
    //  print_itnode(head, 3);
    //  printith_2(head, 3);
    return 0;
    

}
