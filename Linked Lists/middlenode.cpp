#include <iostream>
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

Node* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }       
        if(fast)
        {
            return slow->next; //even
        }
        return slow; //odd
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
