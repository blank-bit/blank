//冒泡排序法 + 函数

#include<stdio.h>

#define N  10

void bubble_sort(int a[],int len)
{
    int i,j;
    for(i = 0;i < len - 1;++i)
        for(j = 0;j< len -i -1;++j)
            if(a[j] >= a[j+1])
            {//block
                int t = a[j];//效率低，可扩大定义范围
                a[j] = a[j+1];
                a[j+1] = t;//转换值
            }
}

void print_array(int a[],int len,int w)
{
    int i;
    for(i = 0;i < len; ++i)
        printf("%*d",w,a[i]);
    putchar('\n');

}

int main()
{
    
    int a[] = {3, 2, 4, 1, 5, 6, 9, 8, 7, 0};
    int b[] = {77,98,876,96,864};

    bubble_sort(a,N);
    print_array(a,N,4);

    bubble_sort(b,5);
    print_array(b,5,6);
    
    return 0;
}