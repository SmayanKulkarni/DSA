#include <iostream>
using namespace std;


void mergearray(int x[], int y[], int a[], int s, int e)
{
    int mid = (s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    while(i<=mid && j<=e)
    {
        if(x[i]<y[j])
        {
            a[k]=x[i];
            i++;
            k++;
        }
        else{
            a[k]=y[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        a[k]=x[i];
        i++;
        k++;
    }
    while(j<=e)
    {
        a[k]=y[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int s, int e)
{
    if(s>=e) return;
    int mid = (s+e)/2;
    int x[100],y[100];  
    for(int i=0;i<=mid;i++)  
    {
        x[i]=arr[i];
    }
    for(int i=mid+1;i<=e;i++)
    {
        y[i]=arr[i];
    }
    mergesort(x,s,mid);
    mergesort(y,mid+1,e);
    mergearray(x,y,arr,s,e);
}
int main()
{
    int arr[10];
    for(int i=0;i<10;i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, 9);
    for(int i=0;i<10;i++)
    {
        cout<< arr[i]<<endl;
    }
}