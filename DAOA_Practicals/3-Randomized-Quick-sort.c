#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int randomIndex = low + rand() % (high - low + 1);
    int pivot = arr[randomIndex];
    int i = low + 1;
    int j = high;

    while(i<=j){
        while(arr[i] <=pivot && i<=high){
            i++;
        }
        while(arr[j] > pivot && j>=low){
            j--;
        }

        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void QuickSort(int arr[], int low, int high){
    if(low < high){
        int mid = partition(arr, low, high);

        QuickSort(arr, low, mid-1);
        QuickSort(arr, mid+1, high);
    }
}

int main(){
    int arr[] = {43,2,67,56,25,789,12,45};
    int n = 8;

    printf("Unsorted Array: \n");
    for(int i = 0;i<8;i++){
        printf("%d, ", arr[i]);
    }

    QuickSort(arr, 0, n-1);

    printf("\nSorted Array: \n");
    for(int i = 0;i<8;i++){
        printf("%d, ", arr[i]);
    }
    
    return 0;
}