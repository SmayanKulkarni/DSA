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

void print_itnode(Node *head, int i)
{
    Node *temp = head;
    int len = length(head);
    if (i >= len) {
        cout << "NULL" << endl;
    }
    else 
    {
        int j = 0;
        while (temp != NULL) {
            if (j != i)
            {
                temp = temp->next;
            }
            else {
                Node *n = new Node(temp->data);
                n->next = NULL;
                cout << n->data << endl;
                return;
            }
            j++;
        }
    }
}

void printith_2(Node *head, int i)
{
    if(i<0)
    {
            cout << "NULL" << endl;
    }

    int count =1;
    while(count <=i && head!= NULL)
    {
        head = head->next;
        count++;
    }
    if(head)
    {
        cout<<head->data<<endl;
    }
    else
    {
        cout<<"NULL";
    }
}

Node* reverseList(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        while(curr)
        {
            Node* n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }
int main()
{
    Node *head = takeinput();
    print(head);
    cout<<length(head)<<endl;
     print_itnode(head, 3);
     printith_2(head, 3);
    return 0;
    

}
