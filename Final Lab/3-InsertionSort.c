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


void InsertionSort(int arr[], int n){
    
    for(int i = 1; i<n; i++){
        int temp = arr[i];
        int j = i-1;

        while( j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
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
    
    InsertionSort(arr, n);
        
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}