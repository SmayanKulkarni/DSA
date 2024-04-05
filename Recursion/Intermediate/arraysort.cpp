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

    bool smallans = sorted(a+1, n-1); //here a+1 is use as a memory reference as in address when one refers to a+1 then the array referred to is the array starting from one element after the original array

    return smallans;
}

bool sorted2(int a[], int n)
{
    if(n==0 || n==1) return true;
    if(a[n-2] >a [n-1])
    {
        return false;
    }
    return sorted2(a,n-1);
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
    bool ans2= sorted2(a,4);
    if(ans == true  )cout<<"Sorted"<<endl;
    if(ans2 == true  )cout<<"Sorted"<<endl;
    else cout<<"Not sorted"<<endl;
    return 0;
}