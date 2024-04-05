#include <bits/stdc++.h>
using namespace std;


int sum(int a[], int n)
{
    if(n==0) return 0;
    if(n==1) return a[0];

    return a[0] + sum(a+1,n-1);
}
int sum2(int a[], int n)
{
    if(n==0) return 0;

    return a[n-1] + sum2(a,n-1);
}
int sum3(int a[], int n, int i)
{
    if(i==n) return 0;
    
    return a[i] + sum3(a,n,i+1);
}
//main to sort the array
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans = sum(a,n);
    int ans2 = sum2(a,n);
    int ans3= sum3(a,n, 0);
   cout<<"Sum: "<<ans3<<endl;
    
    return 0;
}