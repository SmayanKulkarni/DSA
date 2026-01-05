#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int board[20], n;

int place(int row, int col)
{

    for (int i = 1; i < row; i++)
    {
        if (board[i] ==  col || abs(row - i) == abs(board[i] - col))
        {
            return 0;
        }
    }

    return 1;
}

void printSolution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i] == j)
            {
                printf(" Q ");
            }
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

void NQueen(int row)
{

    for (int col = 1; col <=n; col++)
    {
        if (place(row, col))
        {
            board[row] = col;
            if (row == n)
            {
                printSolution();
            }
            else
            {
                NQueen(row + 1);
            }
        }
    }
}

int main()
{

    printf("Enter the number of queens: ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid number of queens.\n");
        return 0;
    }
    NQueen(1);
    return 0;
}