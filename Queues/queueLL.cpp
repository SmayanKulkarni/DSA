
#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    int data;
    Node<T> *next;

    Node(int T)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getsize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size==0;
    }
    void push(T ele)
    {
        Node<T>* n =  new Node<T>(ele);
        if(isEmpty() || head==NULL) 
        {
            head = tail = n;
        }
        
        tail->next = n;
        tail = n;
        size++;
    }
    T front()
    {
        if(isEmpty())
        {
            return 0;
        }
        return head->data;
    }
    void pop()
    {
        if(isEmpty())
        {
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
}
