#include <iostream>
using namespace std;
template <typename T>

class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class Stack
{

public:
    Node<T> *head;
    int size;

    Stack()
    {
        head = NULL;
        size = 0;
    }
    int getsize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(T ele)
    {
        Node<T> *n = new Node<T>(ele);
        n->next = head;
        head = n;
        size++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Empty" << endl;
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack Empty" << endl;
            return 0;
        }
        return head->data;
    }
};

int main()
{
    // Stack<char> s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);

    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;

    Stack<char> s1;
    s1.push(100);
    s1.push(101);
    s1.push(102);
    s1.push(103);
    s1.push(104);

    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
}