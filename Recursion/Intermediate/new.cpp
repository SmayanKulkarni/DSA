#include <bits/stdc++.h>
using namespace std;


int count(int a[], int n,int x, int i)
{
    //base case
    if(i==n) return 0;
    if(a[i] == x) 
    {
        return count(a,n, x,i+1) +1;
    }
    else return count(a,n, x,i+1);
    
}
void count2(int a[], int n,int x, int i, int &ans)
{
    //base case
    if(i==n) return ;
    if(a[i] == x) 
    {
        ans++;
    }
    return count2(a,n, x,i+1, ans);
    
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
    int ans = 0;
    cout<<count2(a,n,x,0,ans)<<endl;   
    return 0;
}