/*********************************************
 @Author       : Mr.Wang
 @Date         : 2021-03-22 19:36:23
 @FilePath     : /test.c
 @Description  : message
*********************************************/
#include "stdio.h"
#include "math.h"

int main()
{
    int x = 54;
    int e = 2;
    int t;
    // t = x / 10 ^ (e - 1);
    // x %= 10 ^ (e - 1);
    t = pow(10, 2);
    x %= 10;
    printf("%d %d\n", t, x);

    t = x / 10 ^ (e - 1);
    x %= 10 ^ (e - 1);
    printf("%d %d", t, x);
    return 0;
}