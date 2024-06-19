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
    cin>>data;

    Node *head = NULL;
    Node *tail = NULL;
    while (data!=-1)
    {

        Node *n = new Node(data);
        if(head==NULL) //1st Node
        {
            head=n;
            tail=n;
        }
        else //Consecutive Nodes
        {
            tail->next = n;
            tail=n;
        }
        cin>>data;
    }
    return head;
}
Node* removeNthFromEnd(Node* head, int k) {
        Node* one = head;
        Node* two = head;

        for(int i=0;i<k;i++)
        {
            two = two->next;
            if(two == NULL)
        {
            return one->next;
        }
        }
      
        while(two->next!=NULL)
        {
            one = one->next;
            two = two->next;
        }
        
        one->next = one->next->next;

        return head;

        
    }
int main()
{
    Node *head = takeinput();
    print(head);

    return 0;

}
