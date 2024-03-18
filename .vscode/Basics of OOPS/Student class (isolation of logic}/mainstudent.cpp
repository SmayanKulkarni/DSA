
#include <iostream>
#include "mainstudentclass.cpp"
using namespace std;
int main()
{
    Student s1;
    Student s2;
    Student s3,s4,s5;
    Student *s6 =  new Student;
    s1.age =24;
    s1.rollno = 101;

    cout<<s1.age<<" "<<s1.rollno<<endl;
    s6->age = 45;   
    s6->rollno = 102;
    return 0;
}