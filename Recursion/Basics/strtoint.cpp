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

int convert(char str[], int n)
{
    if(n==0) return 0;
    int smallans = convert(str, n-1);
    int lastidgit =  str[n-1] - '0';
    int ans = smallans*10 + lastidgit;
    return ans;
}


int main()
{
    char a[10];
    cin>>a;
    int n =length(a);
    cout<<convert(a,n)<<endl;
    cout<<endl;
    return 0;
}