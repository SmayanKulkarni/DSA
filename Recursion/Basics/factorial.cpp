#include <bits/stdc++.h>

using namespace std;
int fact(int n)
{
    if (n<0) return -1;
    if(n ==0) return 1;  // 1st step of PMI
    int smallans = fact(n-1); // 2nd step of PMI, Recursive case
    int ans = n*smallans; //3rd step of PMI : calculation
    return ans;
   
}

int main()
{
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
    return 0;
}