#include <bits/stdc++.h>
using namespace std;

int numberofdigits(int n)
{
    //base case 
    if(n==0) return 0; 
    // recursive case
    int smallans = numberofdigits(n/10);

    // final ans
    return smallans + 1;
}

int main()
{
    int n;
    cin>>n;
    
    cout<<numberofdigits(n)<<endl;
    return 0;

}