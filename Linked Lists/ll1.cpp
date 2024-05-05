#include <iostream>

using namespace std;

class Node {
    public: 
     int data;
     Node *next;

     Node(int data) {
        this->data = data;
        next = NULL;
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

int main()
{
    //statically
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    Node *head = &n1;
    print(head);
   //dynamically
   Node *m1 = new Node(1);
   Node *m2 = new Node(2);
   Node *m3 = new Node(3);
   Node *m4 = new Node(4);
   Node *m5 = new Node(5);
    m1->next = m2;
    m2->next = m3;
    m3->next = m4;
    m4->next = m5;   
//    Node *head2 = m1;
   print(m1);

}