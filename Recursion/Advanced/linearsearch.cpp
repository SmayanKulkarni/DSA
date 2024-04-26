#include <iostream>
#include <string>
using namespace std;


int search(int arr[], int x, int i,int n)
{
    if(i==n) return 0;
    else if (arr[i] == x)
    {
        return x;
    }
    return search(arr, x, i+1,n);
}
int main()
{
    int arr[5];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    int a = search(arr, x,0,5);
    cout<<a<<endl;


}