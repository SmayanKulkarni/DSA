#include <iostream>

using namespace std;

class ComplexNumber
{
    int reans;
    int imans;
    int real;
    int im;
    

    public:
        ComplexNumber(int a,int b)
        {
         real = a;
         im = b;

        }

        void add(ComplexNumber c)
        {
            reans = real + c.real;
            imans = im + c.im;
        }
       void mult(ComplexNumber c)
        {
            reans = real *c.real;
            imans = im * c.im;
        }
        void print()
        {
            cout<<"The answer is "<<reans<<"+i"<<imans<<endl;
        }
};

int main()
{
    int r1, r2,c1,c2;
    cin>>r1>>c1>>r2>>c2;
    ComplexNumber com1(r1,c1);
    ComplexNumber com2(r2,c2);
    int choice;
    cin>> choice;
    if(choice==1)
    {
        com1.add(com2);
        com1.print();
    }
    else if(choice==2)
    {
        com1.mult(com2);
        com1.print();
    }
    return 0;

}

