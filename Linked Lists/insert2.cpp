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
            head->next = n;
            head=n;
        }
        cin>>data;
    }
    return head;
}

int main()
{
    Node *head = takeinput();
    print(head);

    return 0;

}
