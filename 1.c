/*********************************************
 @Author       : Mr.Wang
 @Date         : 2021-06-15 17:17:47
 @FilePath     : /1.c
 @Description  : message
*********************************************/
#include <stdio.h>
#include <string.h>

float set;
int temp = 1500;

int main()
{
    set = (float)temp / 20000;
    printf("%.2f\n", set);
    return 0;
}