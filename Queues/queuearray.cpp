#include <iostream>
using namespace std;
template <typename T>
class Queue
{
    T *arr;
    int nextindex;
    int firstindex;
    int size;
    int cap;

    public: 
        Queue(int capacity){
            cap = capacity;a
            arr = new T[capacity];
            nextindex = 0;
            firstindex = -1;
            size = 0;
        }
        Queue()
        {
            cap = 5;
            arr = new T[5];
            nextindex = 0;
            firstindex = -1;
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
            if(size==cap)
            {
                cout<<"Queue full"<<endl;
                return;
            }
            arr[nextindex] = ele;
            nextindex=(nextindex+1)%cap;
            if(firstindex==-1)
            {
                firstindex =0;
            }
            size++;
            return;
        }

        T front()
        {
            if(isEmpty())
            {
                
                cout<<"Queue is empty"<<endl;
                return 0;
            }

            else return arr[firstindex];
        }

        void pop()
        {
            if(isEmpty())
            {
                cout<<"Queue is empty"<<endl;
                return;
            }
            firstindex= (firstindex+1) %cap;
            size--;
            return;
        }
}