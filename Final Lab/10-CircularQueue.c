#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

int Queue[SIZE];
int rear = -1;
int front = -1;

bool isFull()
{
    if ((rear == SIZE - 1 && front == 0) || rear == front - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty()
{
    if (front == -1)
        return true;
    else
        return false;
}

void Enqueue(int x)
{
    if (isFull())
    {
        printf("Overflow.\n");
    }
    else if (rear == -1 && front == -1)
    {
        front = rear = 0;
        Queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % SIZE;
        Queue[rear] = x;
    }
    return;
}

int Dequeue()
{
    if (isEmpty())
    {
        printf("Underflow.\n");
        return -1;
    }
    else if (front == rear)
    {
        int value = Queue[front];
        front = rear = -1;
        return value;
    }
    else
    {
        int value = Queue[front];
        front = (front + 1) % SIZE;
        return value;
    }
}

void Display()
{

    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        int i = front;
        printf("The Queue is: ");
        do
        {
            printf("%d ", Queue[i]);
            i = (i + 1) % SIZE;
        } while (i != (rear + 1) % SIZE);
    }
    printf("\n");
    return;
}

int main()
{

    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);
    Enqueue(60);

    Display();

    printf("Dequeued: %d\n", Dequeue());
    printf("Dequeued: %d\n", Dequeue());

    Display();

    Enqueue(60);
    Enqueue(70);

    Display();

    return -1;
}
