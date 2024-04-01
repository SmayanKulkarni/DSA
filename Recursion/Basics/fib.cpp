#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    //base case
    if(n==0) return 0;
    if(n==1) return 1;

    //assumptions
    int smallans1 = fib(n-1);
    int smallans2 = fib(n-2);

    // final ans
    return smallans1 + smallans2 ;
}

int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;

}