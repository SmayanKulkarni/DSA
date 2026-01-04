#include <stdio.h>

typedef struct {
    double value;
    double weight;
} Item;

void knapsack(Item items[], int capacity, int n, double result[]){
    double pw[100];

    for(int i = 0; i < n; i++){
        pw[i] = items[i].value / items[i].weight;
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(pw[i] < pw[j]){
                double temp = pw[i];
                pw[i] = pw[j];
                pw[j] = temp;

                Item tempItem = items[i];
                items[i] = items[j];
                items[j] = tempItem;
            }
        }
    }

    for(int i = 0; i < n; i++){
        result[i] = 0;
    }
    
    double val = 0;
    for(int i = 0; i < n; i++){
        if(val + items[i].weight <= capacity){
            result[i] = 1;
            val += items[i].weight;
        }
        else{
            result[i] = (capacity - val) / items[i].weight;
            break;
        }
    }
}

int main(){
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    int n = sizeof(items) / sizeof(items[0]);
    double result[100];
    
    knapsack(items, capacity, n, result);
    
    for(int i = 0; i < n; i++){
        printf("Item %d: %.2f\n", i + 1, result[i]);
    }
    
    return 0;
}


