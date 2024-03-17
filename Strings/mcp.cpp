#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str1[100];
    char str2[100];
    cin.getline(str1,100);
    cin.getline(str2,100);

    int  x=  strcmp(str1,str2);
    cout<<x<<endl;
}