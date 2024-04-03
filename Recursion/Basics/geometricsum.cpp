#include <bits/stdc++.h>

using namespace std;

double gsum(int k)
{
    //base
    if(k==0) return 1;

    //recursive case
    double smallans = gsum(k-1);

    //final ans
    return smallans + 1.0/pow(2,k);
}
int main()
{
    double n;
    cin>>n;
    
    cout<<gsum(n)<<endl;

    return 0;

}