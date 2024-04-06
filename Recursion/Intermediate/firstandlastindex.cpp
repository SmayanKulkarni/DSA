#include <bits/stdc++.h>
using namespace std;


int firstindex(int a[], int n,int x, int i)
{
    //base case
    if(i==n) return -1;
    if(a[i] == x)  return i;

    return firstindex(a,n,x,i+1);
}
int lastindex(int a[], int n,int x, int i)
{
    //base case
    if(i==0) return -1;
    if(a[i] == x)  return i;

    return lastindex(a,n,x,i-1);
}
int lastindex2(int a[], int n,int x)
{
    //base case
    if(n==0) return -1;
    if(a[n-1] == x)  return n-1;

    return lastindex2(a,n-1,x);
}

int main()
{
    int n,x;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>x;
    cout<< lastindex(a,n,x,n-1)<<endl;
    cout<< lastindex2(a,n,x)<<endl;
   
    
    return 0;
}