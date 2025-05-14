int findTheWinner(int n, int k){
    int Queue[n];
    int size = n;

    for (int i =0;i<size;i++){
        Queue[i]=i+1;
    }

    int curr =0;

    while(size>1){
        int to_rem = (curr + k -1)%size;
        for(int i =to_rem;i<size-1;i++)
        {
            Queue[i] = Queue[i+1];
        }
        size--;
        curr = to_rem;
    }

    int Winner = Queue[0];
    return Winner;
}

int main()
{
    int n, k;
    printf("Enter total players (n): ");
    scanf("%d", &n);
    printf("Enter elimination step (k): ");
    scanf("%d", &k);
    printf("\nThe winner is player %d\n", findTheWinner(n, k));
    return 0;
}

