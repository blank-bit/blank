#include <stdio.h>
#include <math.h>
int mian()
{
    float x,sin,f,y;
    int i,sign;
    x=0.5;
    sin=0.0f;
    i=1;
    f=1;
    y=x;
    sign=1;

    while(i<11)
    {
        sin +=sign * y/f;
        sign *= -1;
        y*=x*x;
        f *= (i+1)*(i+2);
        i+=2;
    }
    printf("sinx=");
    return 0;
}