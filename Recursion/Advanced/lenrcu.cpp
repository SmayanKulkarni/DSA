#include <bits/stdc++.h>

using namespace std;

int len(char a[])
{
    if(a[0] == '\0')
    {
        return 0;
    }

    return 1 + len(a+1);
}

int main()
{
    char a[10];
    cin>>a;
    cout<<a<<"\n";
    int n = len(a);
    cout<<n<<"\n";
    return 0;
}