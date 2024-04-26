#include <iostream>
#include <string>
using namespace std;

void checkcase(string &s, int i)
{
    if(i=-1) return;

    s[i] = 'A' + s[i]-'a';
    checkcase(s, i-1);

    
}

int main()
{
    string a= "aeiioodsd";
    int len = a.length();
    checkcase(a, 10);
    cout<<a<<endl;
    return 0;
}