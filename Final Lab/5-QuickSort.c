#include <stdio.h>
#include <stdlib.h>



/*
Logic Behind Insertion Sort:

Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list. It is like sorting playing cards in your hands. You split the cards into two groups: the sorted cards and the unsorted cards. Then, you pick a card from the unsorted group and put it in the right place in the sorted group. 


    1. We start with the second element of the array as the first element is assumed to be sorted.
    2. Compare the second element with the first element if the second element is smaller then swap them.
    3. Move to the third element, compare it with the first two elements, and put it in its correct position
    4. Repeat until the entire array is sorted.
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