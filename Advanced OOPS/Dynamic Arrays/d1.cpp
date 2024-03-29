#include <iostream>
using namespace std;

class dynamicarray
{
    int *data;
    int capacity;
    int index;

public:
    dynamicarray()
    {
        data = new int[5];
        capacity = 5;
        index = 0;
    }
    dynamicarray(dynamicarray const &d)
    {
        this->capacity = d.capacity;
        this->index = d.index;
        this->data = new int[d.capacity];
        for (int i = 0; i < d.index; i++)
        {
            this->data[i] = d.data[i];
        }
    }

    void operator=(dynamicarray const &d)
    {
        this->capacity = d.capacity;
        this->index = d.index;
        this->data = new int[d.capacity];
        for (int i = 0; i < d.index; i++)
        {
            this->data[i] = d.data[i];
        }
    }
    void add(int a)
    {
        if (index == capacity)
        {
            int *newarr = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                data[i] = newarr[i];
            }
            delete[] data;
            data = newarr;
            capacity = 2 * capacity;
        }
        data[index] = a;
        index++;
    }

    void add(int element, int i)
    {
        if (i < index)
        {
            data[i] = element;
        }
        else if (i == index)
        {
            add(element);
        }
        else
            return;
    }

    void get(int i) const
    {
        if (i < 0 || i >= capacity)
        {
            cout << "Invalid index" << endl;
        }
        else
        {
            cout << data[i] << endl;
        }
    }

    void print() const
    {
        for (int i = 0; i < index; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    int getcapacity() const
    {
        return capacity;
    }
};
