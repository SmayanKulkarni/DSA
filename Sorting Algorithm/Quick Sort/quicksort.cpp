#include <iostream>
using namespace std;

int partition(int a[], int s, int e)
{
    int i=s;
    int pivot = a[e];
    for(int j=s; j<=e;j++)
    {
        if(a[j]<pivot)
        {
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[i],a[e]);
    return i;
}

void quicksort(int a[], int s, int e)
{
    if(s>=e) return;
    int p = partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}

int main()
{
    int arr[10];
    for(int i=0;i<10;i++)
    {
        cin >> arr[i];
    }
    quicksort(arr, 0, 9);
    for(int i=0;i<10;i++)
    {
        cout<< arr[i]<<endl;
    }
}