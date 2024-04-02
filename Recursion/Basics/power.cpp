#include <bits/stdc++.h>
using namespace std;

int pow(int d, int n)
{
    //base case
    if(n==0) return 1;
    if(n==1) return d;
    // recursive case 
    int smallans = pow(d,n-1);
    //final ans
    return d*smallans;
}

int main()
{
    int n,d;
    cin>>d;
    cin>>n;
    cout<<pow(d, n)<<endl;
    return 0;

}