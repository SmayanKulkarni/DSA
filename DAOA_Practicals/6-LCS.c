#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int max(int a, int b)
{
    return (a > b) ? a : b;
}

void lcs(char *X, char *Y, int m, int n)
{
    int table[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }

    int length = table[m][n];
    char lcsstr[length + 1];
    lcsstr[length] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcsstr[--length] = X[i - 1];
            i--;
            j--;
        }
        else if (table[i - 1][j] > table[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("LCS length: %d\n", table[m][n]);
    printf("LCS: %s\n", lcsstr);
}

int main()
{
    char X[] = "AGGTABAV";
    char Y[] = "GXTXAYCBB";
    int m = sizeof(X) / sizeof(X[0]) - 1;
    int n = sizeof(Y) / sizeof(Y[0]) - 1;

    lcs(X, Y, m, n);

    return 0;
}
