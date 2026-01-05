/*
 Simple Branch-and-Bound solution for 0/1 Knapsack.
 Approach:
  - Sort items by value/weight ratio (descending).
  - Use DFS with pruning: compute an upper bound using fractional knapsack
    from the current position; if currentValue + bound <= bestValue, prune.
  - Keep track of the best value and the chosen items.

  Input format (stdin):
    n W
    w1 v1
    w2 v2
    ...

  Example:
    4 16
    2 40
    5 30
    10 50
    5 10

  The program prints the maximum value and the chosen item indices (1-based original indices).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int wt;
    int val;
    double ratio;
    int idx; /* original index (1-based) */
} Item;

int n, W;
Item items[100];
int bestTaken[100];
int curTaken[100];
int bestValue = 0;

int cmpRatio(const void *a, const void *b){
    const Item *A = (const Item *)a;
    const Item *B = (const Item *)b;
    if (A->ratio < B->ratio) return 1;
    if (A->ratio > B->ratio) return -1;
    return 0;
}

/* fractional upper bound from item 'i' (0-based) given remaining weight */
double bound(int i, int cw, int cv){
    if (cw >= W) return (double)cv;
    double ub = (double)cv;
    int remW = W - cw;
    for (int k = i; k < n && remW > 0; k++){
        if (items[k].wt <= remW){
            remW -= items[k].wt;
            ub += items[k].val;
        } else {
            ub += items[k].ratio * remW;
            break;
        }
    }
    return ub;
}

void dfs(int i, int cw, int cv){
    if (i == n){
        if (cv > bestValue){
            bestValue = cv;
            for (int k = 0; k < n; k++) bestTaken[k] = curTaken[k];
        }
        return;
    }

    double ub = bound(i, cw, cv);
    if (ub <= bestValue) return; /* prune: no better solution possible */

    /* Try taking item i if it fits */
    if (cw + items[i].wt <= W){
        curTaken[i] = 1;
        dfs(i+1, cw + items[i].wt, cv + items[i].val);
        curTaken[i] = 0;
    }

    /* Try NOT taking item i */
    dfs(i+1, cw, cv);
}

int main(void){
    printf("Enter number of items and knapsack capacity (n W): ");
    fflush(stdout);
    if (scanf("%d %d", &n, &W) != 2){
        fprintf(stderr, "Invalid input. Expected: n W\n");
        return 1;
    }
    if (n <= 0 || n > 100){
        fprintf(stderr, "n must be between 1 and 100\n");
        return 1;
    }

    for (int i = 0; i < n; i++){
        printf("Enter weight and value for item %d: ", i+1);
        fflush(stdout);
        if (scanf("%d %d", &items[i].wt, &items[i].val) != 2){
            fprintf(stderr, "Invalid input. Expected: wt val\n");
            return 1;
        }
        items[i].ratio = (double)items[i].val / items[i].wt;
        items[i].idx = i+1;
        curTaken[i] = 0;
        bestTaken[i] = 0;
    }

    /* sort by ratio desc for better bounds */
    qsort(items, n, sizeof(Item), cmpRatio);

    dfs(0, 0, 0);

    printf("Max value = %d\n", bestValue);
    printf("Taken items (original indices):");
    for (int i = 0; i < n; i++){
        if (bestTaken[i]) printf(" %d", items[i].idx);
    }
    printf("\n");

    return 0;
}
