#include <stdio.h>
#include <stdlib.h>



/*
Logic Behind Linear Search:

Linear Search is a simple searching algorithm that loops over the entire array and individually checks if the 
element of the array matches the key or not, if it matches the key it returns the index, if the key is not 
found then it returns -1.
*/


int LinearSearch(int arr[], int n, int x){

    for (int i =0;i<n;i++){
        if(arr[i] == x) 
        {
            printf("\nThe Element is found at %d index", i);
            return i;
        }
    }
    printf("Element not found in this list!");
    return -1;

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
    int idx;
    printf("Original array: "); 
    printArray(arr, n);
    
    idx = LinearSearch(arr, n, 3451);
        
    return 0;
}