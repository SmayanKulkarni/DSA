#include <iostream>
using namespace std;

class Student 
{
    

    public: 
    int rollNumber;
    int age;
    static int totalStudents;

    Student()
    {
        totalStudents++;
    }
    int getrollNumber()
    {
        return rollNumber;
    }
    static int gettotalStudents()
    {
        return totalStudents;
    }
};

int Student::totalStudents = 0;