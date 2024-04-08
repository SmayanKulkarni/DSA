#include <bits/stdc++.h>
using namespace std;


int storeallindexes(int a[], int n,int x, int i, int out[], int j)
{
    //base case
    if(i==n) return 0 ;
    if(a[i] == x) 
    {
        out[j] =i;
        return 1+storeallindexes(a,n,x,i+1,out,j+1);
    }

    return 0+ storeallindexes(a,n,x,i+1,out,j);
}

void storeallindexes2(int a[], int n,int x, int i,vector<int> &ans)
{
    //base case
    if(i==n) return ;
    if(a[i] == x) 
    {
        ans.push_back(i);
    }

    return storeallindexes2(a,n,x,i+1,ans);
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
    vector<int> v;
    cin>>x;
    storeallindexes2(a,n,x,0,v);
    //for vector method
     for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
     cout<<endl;
    int out[10];
    int count = storeallindexes(a,n,x,0,out,0);
    // for array method
    for(int i=0;i<count;i++)
    {
        cout<<out[i]<<" ";
    }
    return 0;
}