#include <iostream>
#include "student.cpp"

int main()
{
    Student s1;
    Student s2;
    Student *s3 = new Student;
    Student s4;
    cout << Student::totalStudents << endl;
    return 0;
}   