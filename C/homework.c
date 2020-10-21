#include<stdio.h>

int main()
{
    int a[4][4];
    int i,j;
    printf("Enter the array:");
    for(i = 0;i < 4;i++)   
    {   
        for(j = 0;j < 4;j++)
            scanf("%d",&a[i][j]);
    }
    
    int min = a[0][0]; 
    for(i = 0;i < 4;i++)
    {
        if(a[i][i] < min)
            min = a[i][i];
    }
    printf("The min is %d",min);
    return 0;
}