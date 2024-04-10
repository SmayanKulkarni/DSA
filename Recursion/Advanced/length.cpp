#include <bits/stdc++.h>
using namespace std;

int length(char a[])
{
    if(a[0]=='\0')
    {
        return 0;
    }
    return 1+ length(a+1);
}


int main()
{
    char a[10];
    cin>>a;
    cout<<length(a)<<endl;
    cout<<endl;
    return 0;
}