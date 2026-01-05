#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int id;
    int dead;
    int profit;

} Job;

int CompJobs(const void *a, const void *b)
{
    const Job *jobA = (const Job *)a;
    const Job *jobB = (const Job *)b;
    /* sort by profit descending */
    return jobB->profit - jobA->profit;
}

void JobScheduling(Job jobs[], int n)
{
    qsort(jobs, n, sizeof(Job), CompJobs);

    /* find maximum deadline to size slots */
    int max_dead = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].dead > max_dead)
            max_dead = jobs[i].dead;
    if (max_dead <= 0)
        max_dead = 0;

    int result[max_dead];
    int slot[max_dead];
    for (int i = 0; i < max_dead; i++)
    {
        slot[i] = 0;
        result[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].dead - 1; j >= 0; j--)
        {
            if (slot[j] == 0)
            {
                slot[j] = 1;
                result[j] = i; /* store index in sorted jobs[] */
                break;
            }
        }
    }

    /* print scheduled jobs in time order and compute total profit */
    printf("Following is the maximum profit sequence of jobs:\n");
    int totalProfit = 0;
    for (int t = 0; t < max_dead; t++)
    {
        if (result[t] != -1)
        {
            Job j = jobs[result[t]];
            printf("Time %d: Job %d (profit %d)\n", t + 1, j.id, j.profit);
            totalProfit += j.profit;
        }
    }
    printf("Total Profit = %d\n", totalProfit);
}

int main()
{
    Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    JobScheduling(jobs, n);
    printf("Following is the maximum profit sequence of jobs \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", jobs[i].id);
        return 0;
    }
}