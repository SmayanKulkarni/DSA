#include <stdio.h>
#include <stdlib.h>



/*
Logic Behind Selection Sort:

Selection Sort is a comparison-based sorting algorithm. It sorts an array by repeatedly selecting the smallest (or largest) element from the unsorted portion and swapping it with the first unsorted element. This process continues until the entire array is sorted.

1. First we find the smallest element and swap it with the first element. This way we get the smallest element at its correct position.
2. Then we find the smallest among remaining elements (or second smallest) and swap it with the second element.
3. We keep doing this until we get all elements moved to correct position.
*/

void selectionSort(int arr[], int n){
    int i,j, min_idx, temp;

    for(i = 0;i<n-1;i++){

        min_idx = i;

        for (j=i+1; j<n;j++){
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
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

    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: "); 
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}