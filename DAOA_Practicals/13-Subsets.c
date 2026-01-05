#include <stdio.h>
#include <stdlib.h>

int w[10], x[10], d;

void sumofsubset(int s, int k, int n)
{
    int i;
    int b = 1;

    if (k >= n) return;

    x[k] = 1;
    if (s + w[k] == d)
    {
        printf("In subset:");
        for (i = 0; i <= k; i++)
        {
            if (x[i] == 1)
                printf(" %d", w[i]);
        }
        printf("\n");
    }
    else if (k + 1 < n && s + w[k] + w[k + 1] <= d) {
        sumofsubset(s + w[k], k + 1, n);
    }

    x[k] = 0;
    /* try exclude current item and move to next if exists */
    if (k + 1 < n && s + w[k + 1] <= d)
        sumofsubset(s, k + 1, n);
}


int main()
{

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    printf("Enter the desired sum: ");
    scanf("%d", &d);
    printf("The subsets with sum %d are:\n", d);
    sumofsubset(0, 0, n);
    

    return 0;
}