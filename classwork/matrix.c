#include<stdio.h>
int main()
{
    #define M 3
    #define N 5
    #define K 3
    
    int a[M][N] = {{1,5},{0,1},{0,0,1}} ,b[N][K] = {{4,7},{0,1},{0,0,1}},c[M][K];
    int i,j,k;

    for (i = 0;i < M ;i++)
        for(j = 0; j < K;j++)
        {
            int sum = 0;
            for (k = 0;k < N; ++k)
                sum += a[i][k] * b[k][j];
            c[i][j] = sum;
        }
            
    for (i = 0 ;i < M; i++ )
    {
        for(j = 0;j < K; j++)
        printf("%4d",c[i][j]);
        printf("\n");
    }        
    return 0;
}