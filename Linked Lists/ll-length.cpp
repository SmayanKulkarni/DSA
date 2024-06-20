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

Node* takeinput1() // for inserting at the end
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
            tail= n;
        }
        cin>>data;
    }
    return head;
}

Node* takeinput2() // for inserting at the end
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
            tail =n;
        }
        cin>>data;
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

int main()
{
    Node *head = takeinput1();
    print(head);
    cout<<length(head)<<endl;
    return 0;

}

