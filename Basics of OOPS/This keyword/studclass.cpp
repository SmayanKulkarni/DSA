#include <iostream>
using namespace std;
class student
{
  int age;
  public: 
    student(int a, int r)
    {
        cout<<"this: "<<this<<endl;
        age =a;
    }};
