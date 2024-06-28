#include <iostream>
using namespace std;
template <typename T>
class Queue
{
    T *arr;
    int nextindex;
    int firstindex;
    int size;

    public: 
        Queue(int cap){
            arr = new T[cap];
            nextindex = 0;
            firstindex = -1;
            size = 0;
        }
        Queue()

        
        {
            arr = new T[5];
            nextindex = 0;
            firstindex = -1;
            size = 0;
        }
}