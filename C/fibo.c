#include<stdio.h>

long fibo(long n,long a,long b)//long fibo(long n)
{
    //return n <= 2 ? 1 : fibo(n-1) + fibo(n-2);
    return n == 1 ? a : fibo(n-1, b ,a+b);  
}

int main()
{
    long i;
    scanf("%ld",&i);
    printf("%ld",fibo(i,1,1));
    return 0;
}