#include <bits/stdc++.h>
using namespace std;


int minelement(int arr[], int i, int n)
{
    //base case
    if(i==n-1) return arr[i];

    return min(arr[i], minelement(arr, i+1,n));
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
    
   int mine = minelement(a,0,n);
    cout<<mine<<endl;
    return 0;
}