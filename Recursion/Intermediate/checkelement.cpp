#include <bits/stdc++.h>
using namespace std;


bool checkelement(int a[], int n,int x)
{
    //base case
    if(n==0) return false;

    if(a[0] == x) return true; 
    
    //recursive case
    bool smallans = checkelement(a+1, n-1,x); 
    return smallans;  
}
bool checkelement2(int a[], int n,int x)
{
    //base case
    if(n==0) return false;

    if(a[n] == x) return true; 
    
    //recursive case
    int smallans = checkelement2(a, n-1,x); 
    return smallans;  
}
bool checkelement3(int a[], int n,int x, int i)
{
    //base case
    if(n==i) return false;

    if(a[i] == x) return true; 
    
    //recursive case
    bool smallans = checkelement3(a, n,x, i+1); 
    return smallans;  
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
   if(checkelement3(a,n,x,0)==true) cout<<"Found";
   else cout<<"Not found";
    
    return 0;
}