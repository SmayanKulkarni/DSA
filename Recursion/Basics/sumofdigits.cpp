#include <bits/stdc++.h>
using namespace std;

int sumofdigits(int n)
{
    //base case 
    if(n==0) return 0; 
    // recursive case
    int smallans = sumofdigits(n/10);

    // final ans
    return smallans + n%10;
}

int main()
{
    int n;
    cin>>n;
    
    cout<<sumofdigits(n)<<endl;
    return 0;

}