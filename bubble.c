//冒泡排序法

#include<stdio.h>
#define N 10
int main()
{
    
    int a[]={3, 2, 4, 1, 5, 6, 9, 8, 7, 0};
    int i,j;
    for(i = 0;i < N - 1;++i)
        for(j = 0;j< N -i -1;++j)
            if(a[j] >= a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;//转换值
            }
    for(i = 0;i < N; ++i)
        printf("%4d",a[i]);
    putchar('\n');

    return 0;
}