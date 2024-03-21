#include <iostream>
#include <cstring>
using namespace std;

class Student 
{
    int age;
    char *name;

    public: 
        char *name;
        Student (Student const &s) // deep copy constructor
        {
            this->age =s.age;
            this->name = new char[strlen(s.name)+1]; 
            strcpy(this->name, s.name);
        }
        Student(int age, char *name)
        {
            this->age = age;
            this->name = name; // shallow copy
            this->name = new char[strlen(name)+1];  
            strcpy(this->name, name);
        }
        void display()
        {
            cout<<name<< " "<<age<<endl;
        }
};

int main()
{
    char name[] ="abcd";
    Student s1(20,name);
    s1.display();
    name[3] ='e';
    Student s2(30,name);
    s2.display();
    s1.display();
    return 0;
}