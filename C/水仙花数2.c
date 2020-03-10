#include<stdio.h>
#include<math.h>

int main()
{
    int a, b , c, n;

    for(n = 100; n < 1000; ++n)
    {
        a = n / 100;
        b = n / 10 % 10;
        c = n % 10;
        if (a * a * a + b * b * b + c * c * c == n)
        printf("%d\n",n);
    }
    return 0;
}