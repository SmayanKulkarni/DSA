#include <bits/stdc++.h>
using namespace std;

int zeros(int n)
{
    //base case
    if(n==0) return 0;
    //recursive case 
    int smallans = zeros(n/10);
    //final ans
    if(n%10 ==0) return smallans+1;
    else return smallans;
}


int main()
{
    int n,m;
    cin>>n;
   
    
    cout<<zeros(n)<<endl;
   
    return 0;

}