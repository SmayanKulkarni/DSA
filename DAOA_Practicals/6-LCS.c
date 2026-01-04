#include <stdio.h>
#include <stdlib.h>


#define MAX 100
#define INF 9999

void lcs(char *X, char *Y, int m, int n){
    
    int table[m+1][n+1];

    for(int i = 0;i<=m;i++){
        for(int j =0;j<=n;j++){
            if(i==0 || j==0){
                table[i][j] =0;
            }
        }
    }

    for(int i = 0;i<=m;i++){
        for(int j =0;j<=n;j++){
            
            if(X[i] == Y[i]){
                table[i][j] = 1 + table[i-1][j-1];
            }
            else if(table[i-1][j] >= table[i][j-1]){
                table[i][j] = table[i-1][j];
            }
            else{
                table[i][j] = table[i][j-1];
            }
        }
    }
}

int main(){
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = sizeof(X)/sizeof(X[0]) - 1;
    int n = sizeof(Y)/sizeof(Y[0]) - 1;

    lcs(X, Y, m, n);

    return 0;
}

