#include<stdio.h>
int main()
{
    #define N 9
    
    int a[N][N];
    int i,j;
    for (i = 0;i < N ;i++)
        for(j = 0; j < N;j++)
            a[i][j]=(i + 1) * (j + 1);
    for (i = 0 ;i < N; i++ )
    {
        for(j = 0;j < N; j++)
        printf("%4d",a[i][j]);
        printf("\n");
    }        
    return 0;
}