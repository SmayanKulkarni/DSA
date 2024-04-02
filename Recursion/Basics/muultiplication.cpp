#include <bits/stdc++.h>
using namespace std;

int mult(int n, int m)
{
    //base case
    if(m==0) return 0;
    if(m==1) return n;
    //recursive case 
    int smallans = mult(n,m-1);
    //final case
    return n+smallans;
}


int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    
    cout<<mult(n,m)<<endl;
    return 0;

}