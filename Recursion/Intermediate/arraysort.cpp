#include <bits/stdc++.h>
using namespace std;


bool sorted( int a[], int n)
{
    //base case
    if(n==0 || n==1) return true;
    if (a[0] > a[1])
    {
        return false;
    }
    //recursive case

    bool smallans = sorted(a+1, n-1);

    return smallans;
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
    bool ans = sorted(a,4);
    if(ans == true) cout<<"Sorted"<<endl;
    else cout<<"Not sorted"<<endl;
    return 0;
}