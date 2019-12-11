#include <stdio.h>

int main()
{
    #define N 11
    int yh[N][N]={0};
    int i,j;

    for (i = 0;i <= N/2;i++)
        {
            yh[i][N/2 - i] = 1;
            yh[i][N/2 + i] = 1;
        }
    
    for(i = 2;i <= N/2;i++)
    {
        for(j = 0;j < N-1;j++)
            if(yh[i-1][j+1] != 0)
            yh[i][j] = yh[i-1][j-1] + yh[i-1][j+1];
    }

    for(i = 0;i <= N/2;i++)
    {
        for(j = 0;j < N;j++)
        if(yh[i][j] != 0)
            printf("%-2d",yh[i][j]);
        else
            printf("  ");
        printf("\n");
    }
    return 0;
}