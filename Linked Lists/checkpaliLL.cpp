
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *takeinput()
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
        cin >> data; // imp
    }
    return head;
}

int length(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *mergeTwoLists(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *newHead = NULL;
    if (a->data < b->data)
    {
        newHead = a;
        newHead->next = mergeTwoLists(a->next, b);
    }
    else
    {
        newHead = b;
        newHead->next = mergeTwoLists(a, b->next);
    }
    return newHead;
}

bool isPalindrome(Node *head)
{
    if (head->next == NULL)
        return 1;
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    Node *curr = head, *prev = NULL;
    count /= 2;
    for (int i = 0; i < count; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    prev = NULL;
    Node *front;
    while (curr)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    Node *head1 = head, *head2 = prev;
    while (head1)
    {
        if (head1->data != head2->data)
        {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return 1;
}

Node *deleteithNode(Node *head, int i)
{
    if (i < 0)
    {
        return head;
    }
    if (i == 0 && head)
    {
        Node *newHead = head->next;
        head->next = NULL;
        delete head;
        return newHead;
    }

    Node *curr = head;
    int count = 0;
    while (count <= i - 1 && curr != NULL)
    {
        curr = curr->next;
        count++;
    }
    if (curr && curr->next)
    {
        Node *temp = curr->next;
        curr->next = curr->next->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    return head;
}

Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *n = slow->next;
    slow->next = NULL;

    Node *a = sortList(head);
    Node *b = sortList(n);

    head = mergeTwoLists(a, b);

    return head;
}
int main()
{
    Node *head = takeinput();
    Node a(3);
    Node b(5);
    

    return 0;
}
