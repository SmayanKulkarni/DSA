#include <iostream>

class Stack
{
private:
    int *arr;
    int nextIndex;
    int capacity;

public:
    Stack()
    {
        arr = new arr[4];
        nextIndex = 0;
    }
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int ele)
    {
        if (nextIndex == capacity)
        {
            int *newarr =  new int[2*capacity];
            for (int i = 0; i < 2*capacity; i++)
            {
                newarr[i] = arr[i];
            }
            delete[] arr;
            arr = newarr;
            capacity = 2*capacity;
        }
        arr[nextIndex++] = ele;
        nextIndex++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack empty" << endl;
            return;
        }
        nextIndex--;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[nextIndex - 1];
    }
};

int main()
{
    Stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
}