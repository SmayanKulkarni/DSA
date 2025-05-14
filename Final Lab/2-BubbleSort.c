#include <stdio.h>
#include <stdlib.h>



/*
Logic Behind Bubble Sort:

Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. This algorithm is not suitable for large data sets as its average and worst-case time complexity are quite high.

1. First we loop through the entire Array
2. For every single iteration of the array, we again iterate through the remaining array and swap the element when '>' or '<' condition is met.
*/

void BubbleSort(int arr[], int n){
    int i,j, temp;

    for(i = 0;i<n-1;i++){
        for (j=0; j<n-i-1;j++){
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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
    
    BubbleSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}