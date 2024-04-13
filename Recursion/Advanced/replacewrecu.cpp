#include <bits/stdc++.h>

using namespace std;

void replace(char a[], char x, char y)
{
    if(a[0] == '\0')
    {
        return;
    }
    if(a[0] == x)
    {
        a[0] = y;
    }

    replace(a+1, x, y);
    
}

int main()
{
    char a[10];
    cin>>a;
    cout<<"Before Replacement: "<<a<<endl;
    cout<<"After Replacement: ";
    replace(a,'A','B');
    cout<<"After Replacement: "<<a<<endl;

    return 0;
}