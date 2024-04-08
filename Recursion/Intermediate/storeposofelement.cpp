#include <bits/stdc++.h>
using namespace std;


vector<int> storepos(int a[], int n,int x, int i)
{
    //base case
    if(i==n) return 0;
    if(a[i] == x) 
    {
        storepos.push_back(a[i]);
        return count(a,n, x,i+1) +1;
    }
    else return count(a,n, x,i+1);
    
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