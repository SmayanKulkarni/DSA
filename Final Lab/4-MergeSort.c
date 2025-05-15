#include <stdio.h>
#include <stdlib.h>



/*
Logic Behind Selection Sort:

Merge sort is a popular sorting algorithm known for its efficiency and stability. It follows the divide-and-conquer approach. It works by recursively dividing the input array into two halves, recursively sorting the two halves and finally merging them back together to obtain the sorted array.


1.Divide:  Divide the list or array recursively into two halves until it can no more be divided. 
2.Conquer:  Each subarray is sorted individually using the merge sort algorithm. 
3. Merge:  The sorted subarrays are merged back together in sorted order. The process continues until all   elements from both subarrays have been merged
*/

void merge(int arr[], int mid, int low, int high){
    int i,j,k,B[100];
    i = low;
    j = mid +1;
    k = low;

    while(i<=mid && j <=high) {
        if (arr[i] < arr[j]){
            B[k] = arr[i];
            i++;
            k++;
        }
        else{
            B[k] = arr[j];
            j++;
            k++;
        }
    }

    while(j<=high){
        B[k] = arr[j];
        j++;
        k++;
    }
    
    while(i<=mid){
        B[k] = arr[i];  
        i++;
        k++;
    }

    

    for (i = low; i<=high; i++){
        arr[i] = B[i];
    }
}

void MergeSort(int arr[], int low, int high){
    
    int mid;

    if(low<high) {
        mid = (low + high) /2;  
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        merge(arr, mid, low, high);

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
    
    MergeSort(arr, 0,n-1);
        
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}