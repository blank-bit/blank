#include <stdio.h>

int main()
{
    int x = 1,i,j;
    int n = 4;
    for(i = 0 ; i < n ; i++)
        for(j = i; j < n; j++)
            x++;
    printf("%d",x);
    return 0;
}