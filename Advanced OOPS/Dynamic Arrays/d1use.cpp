#include <iostream>
#include "d1.cpp"

using namespace std;

int main()
{
    dynamicarray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    d1.print();
    cout<<d1.getcapacity()<<endl;
    dynamicarray d2(d1);
    d1.add(100,0);
    d1.print();
    d2.print();
    dynamicarray d3;
    d3=d1;
    d3.print();


    
    return 0;
}