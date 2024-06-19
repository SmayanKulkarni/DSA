#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* sortList(ListNode *head)
{
    
    ListNode *first = head;
    ListNode *second = head->next;
    while (head && head->next)
    {
        
        if (first->val > second->val)
        {
            ListNode *temp = second->next;
            second->next = first;
            first->next = temp;
            head = second;
        }
        first = first->next;
        second = second->next;
    }
    if(!head->next) return head;
    return head;
}
ListNode* takeinput()
{
    int val;
    cin >> val;

    ListNode *head = NULL;
    ListNode *tail = NULL;
    while (val != -1)
    {
        ListNode *n = new ListNode(val);
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
        cin >> val;
    }
    return head;
}


int length(ListNode *head)
{
    int count=0;
    ListNode *temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
   return count; 

}

void print(ListNode *head)
{
    ListNode *temp = head;

    while(temp!=NULL) {
        cout<<temp->val<<endl;
        temp = temp->next;
    }
}
int main()
{
    ListNode* n1 = takeinput();
    sortList(n1);
    print(n1);
}