#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

int Stack[SIZE];
int top = -1;

bool isFull()
{
    if (top == SIZE - 1)
    {
        return true;
    }

    return false;
}

bool isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

void push(int x)
{

    if (isFull())
    {
        printf("Stack Overflow!!\n");
        return;
    }

    else
    {
        Stack[++top] = x;
    }
}

int pop()
{

    if (isEmpty())
    {
        printf("Stack Underflow!!\n");
        return -1;
    }
    else
    {
        int value = Stack[top--];
        return value;
    }
}

int Peek(){
    if(isEmpty()){
        printf("Stack is Empty!\n");
        return -1;
    }
    else{
        int value = Stack[top];
        return value;
    }
}

void Display(){

    if(isEmpty()){
        printf("Stack is empty!\n");
        return;
    }
    int temp = top;

    while(temp>=-0){
        printf("%d " , Stack[temp--]);
    }
    return;
}

int main(){

    Display();
    printf("\n");
    push(13);
    push(14);
    push(15);
    Display();
    printf("\n");
    int removed1 = pop();
    int removed2 = pop();
    printf("\n");
    Display();

    return 0;
}