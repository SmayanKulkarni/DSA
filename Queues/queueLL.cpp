
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
    }
    bool isEmpty()
    {
    }
    void push(T ele)
    {
    }
    T front()
    {

    }
    void pop()
    {
        
    }
}
