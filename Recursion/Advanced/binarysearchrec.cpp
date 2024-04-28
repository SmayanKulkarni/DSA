#include <iostream>
#include <string.h>

using namespace std; 

bool binary(int arr[],int x, int s, int e)
{
    if(s>e) return 0;
    int mid = s+(e-s)/2;
    if(arr[mid] ==x) {
        return 1;
    }
    else if(arr[mid] >x){
        return binary(arr,x,s,mid-1);
    }
    else {
        return binary(arr,x,mid+1,e);;
    }
}

int main()
{
       int arr[5];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i]; // minor change
    }
    int x;
    cin>>x;
    int a = binary(arr, x,0,5);
    cout<<a<<endl;
}