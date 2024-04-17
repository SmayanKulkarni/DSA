#include <bits/stdc++.h>

using namespace std;

int gcd(int n1,int n2)
{
    if(n2==0)
    {
        return n1;
    }

    return gcd(n2,n1%n2);
    
}

int main()
{
    int n1,n2;
    cin>>n1;
    cin>>n2;
    cout<<gcd(n1,n2)<<endl;
    return 0;

}