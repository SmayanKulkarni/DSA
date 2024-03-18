#include <iostream>
using namespace std;

class Student
{
    int age;
public: 
    int rollno;
    void display()
    {
        cout<<age<<" "<<rollno<<endl;   
    }
    void setAge(int a, int password)
    {
        if(age<0) return;
        if(password != 123) return;
        age = a;
    }
    int getAge()
    {
        return age;
    }
};