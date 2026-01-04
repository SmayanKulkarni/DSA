#include <stdio.h>
#include <stdlib.h>


void combine(int arr[], int low, int  mid, int high){

    int i = low;
    int j = mid + 1;
    int k = low;
    int temp[1000];
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i<= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j<= high){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for(int p = low; p <= high; p++){
        arr[p] = temp[p];
    }
}
void MergeSort(int arr[], int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        combine(arr, low, mid, high);
    }
    return;
    
}




int main(){


    int arr[] = {43,2,67,56,25,789,12,45};
    int n = 8;
    for(int i = 0;i<8;i++){
        printf("%d, ", arr[i]);
    }

    MergeSort(arr, 0, n-1);
    printf("\nSorted Array: \n");
    for(int i = 0;i<8;i++){
        printf("%d, ", arr[i]);
    }

    return 0;
}