#include <iostream>
#include "student2.cpp"

using namespace std;

int main()
{
    Student s1;
    Student *s2 = new Student;
        s1.setAge(34, 123);
        s2->setAge(32,345);
    s1.display();
    s2->display();
    return 0;
}