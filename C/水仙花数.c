#include<stdio.h>
#include<math.h>

int main()
{
    int a, b , c;

    for(a = 1; a < 10; ++a)
        for(b = 0;b < 10 ; ++b)
            for(c = 0;c < 10; ++c)
    {
        
        if (a * a * a + b * b * b + c * c * c == 100*a+10*b+c)
        printf("%d%d%d\n",a,b,c);
    }
    return 0;
}