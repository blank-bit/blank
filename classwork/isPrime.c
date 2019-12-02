#include<stdio.h>
#include <stdbool.h>

int main()
{
    int i,n,r;
    bool isPrime = true;
    scanf("%d",&n);
    for (i=2;i < n; ++i)
    {
        r = n % i;
        if(r==0)
        isPrime = false;
        break;   
    }
    printf(isPrime ? "yes" :"no");
    return 0;
}