#include <bits/stdc++.h>

using namespace std;

int linearsearch(int a[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i]==key) return i;
        
        
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    int pos = linearsearch(a,n,key);
    if(pos==-1)
    {
        cout<< "Key not found"<<endl;
    }
    else
    {
        cout<< "Key found at position: "<<pos<<endl;
    }
    return 0;
}