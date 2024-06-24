#include <iostream>
using namespace std;
template<typename T>
class Stack
{
private:
    T *arr;
    int nextIndex;
    int capacity;

public:
    Stack()
    {
        arr = new T[4];
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

    void push(T ele)
    {
        if (nextIndex == capacity)
        {
            T *newarr =  new T[2*capacity];
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

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return arr[nextIndex - 1];
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    Stack<int> s1;
    s1.push(100);
    s1.push(101);
    s1.push(102);
    s1.push(103);
    s1.push(104);

    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
}