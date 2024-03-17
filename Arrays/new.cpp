
#include <iostream>

using namespace std;

 class Student 
{
    int rollno;
    int age;
   
};

int main()
{
    Student s1;
    Student s2;
    Student s3,s4,s5;
    Student *s6 =  new Student;
    s1.age =24;
    s1.rollno = 101;

    cout<<s1.age<<" "<<s1.rollno<<endl;
    return 0;
}