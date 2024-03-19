#include <iostream>
#include "studclass.cpp"

int main()
{
    student s1(20,200);
    cout<<"Student s1 address : "<<&s1<<endl;
    student s2(20,30);
    cout<<"Student s2 address : "<<&s2<<endl;
    return 0;
}