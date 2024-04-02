
#include <bits/stdc++.h>
using namespace std;
void printascending(int n)
{
    if(n==0) return;
    printascending(n-1);
    cout<<n<<endl;
    return;
}

void printdescending(int n)
{
    if(n==0) return;
    cout<<n<<endl;
    printdescending(n-1);
    
    return;
}

int main()
{
    int n;
    cin>>n;
    printascending(n);
    printdescending(n);
    return 0;

}