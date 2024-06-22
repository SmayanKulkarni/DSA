
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
-
    void
    print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

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

Node *mergeTwoLists(Node *l1, Node *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    Node *finalTail = NULL;
    if (l1->data < l2->data)
    {
        finalTail = l1;
        l1 = l1->next;
    }
    else
    {
        finalTail = l2;
        l2 = l2->next;
    }

    // Node* finalTail = finalHead;
    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            finalTail->next = l1;
            l1 = l1->next;
        }
        else
        {
            finalTail->next = l2;
            l2 = l2->next;
        }
        finalTail = finalTail->next;
    }
    if (l1)
    {
        finalTail->next = l1;
    }
    else
    {
        finalTail->next = l2;
    }

    return finalTail;
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
    print(head);

    return 0;
}
