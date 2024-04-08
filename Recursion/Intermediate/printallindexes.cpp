#include <bits/stdc++.h>
using namespace std;


void allindexes(int a[], int n,int x, int i)
{
    //base case
    if(i==n) return;
    if(a[i] == x) 
    {
        cout<<i<<" ";
    }

    return allindexes(a,n, x,i+1);
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
    allindexes(a,n,x,0);
    
    
    return 0;
}