#include <stdio.h>
#include <stdlib.h>



/*
Logic Behind Quick Sort:

QuickSort is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.

It works on the principle of divide and conquer, breaking down the problem into smaller sub-problems.

    1. Choose a Pivot: Select an element from the array as the pivot. The choice of pivot can vary (e.g., first element, last element, random element, or median).
    2. Partition the Array: Rearrange the array around the pivot. After partitioning, all elements smaller than the pivot will be on its left, and all elements greater than the pivot will be on its right. The pivot is then in its correct position, and we obtain the index of the pivot.
    3. Recursively Call: Recursively apply the same process to the two partitioned sub-arrays (left and right of the pivot).
    4. sBase Case: The recursion stops when there is only one element left in the sub-array, as a single element is already sorted.
*/


int partition(int arr[], int s, int e)
{
    int i=s;
    int temp;
    int pivot = arr[s];
    for(int j=s; j<=e;j++)
    {
        if(arr[j]<pivot)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    temp = arr[i];
    arr[i] = arr[e];
    arr[e] = temp;
    i++;
    return i;
}

void quicksort(int a[], int s, int e)
{
    if(s>=e) return;
    int p = partition(a,s,e);
    quicksort(a,s,p-1);
    quicksort(a,p+1,e);
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main()
{

    int arr[] = {64, 25, 12, 22, 11, 234, 345, 123};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: "); 
    printArray(arr, n);
    
    quicksort(arr, 0, n-1);
        
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}