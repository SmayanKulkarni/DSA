#include <bits/stdc++.h>
using namespace std;

void print(char a[])
{
    if(a[0]=='\0')
    {
        return;
    }
    cout<<a[0];
    print(a+1);
}

void revprint(char a[])
{
    if(a[0]=='\0')
    {
        return;
    }
    print(a+1);
    cout<<a[0];
    
}

int main()
{
    char a[10];
    cin>>a;
    print(a);
    cout<<endl;
    revprint(a);

    cout<<endl;
    return 0;
}