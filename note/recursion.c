#include<stdio.h>

unsigned long fact(unsigned long n)
{
    if (n <= 1) return 1;//return n <= 1 ? 1 : fact(n - 1) * n
    else return fact(n - 1) * n;// return 返回一个确定的值
}

//fact(4) => return fact(3)*4;值不确定往下
//fact(3) => return fact(2)*3;
//fact(2) => return fact(1)*2; => return 1 * 2;
//fact(1) => return 1; 开始返回到上一行
//逐层递归

int main()
{
    unsigned long a;
    scanf("%ld",&a);
    printf("%ld",fact(a));
    return 0;
}