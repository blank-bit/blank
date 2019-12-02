#include<stdio.h>

int main()
{
    int a[] = {1,2,3,4,5};//数组名字是指针 即a = *a
    //a === &a[0] 恒等
    //*(a+i) === &a[i]
    //a的类型为 int [5]
    int *p;
    //p的类型 int *
    
    int i;
    p = &a[0];
    p = a;
    //p[i] === a[i]
    //*(p+i) === *(a+i)
    //p+i === a+i
    //a[i] === *(i+a) === i[a]
    //for(i = 0;i <5;i++)
    //    printf("%4d",a[i]);
    //putchar('\n');
    //++p;
    //p += 3;

    //p + (p - q) / 2;//指针相加无意义，相减中间隔几个单元，指针加整数有意义
    //p == q;

    //printf("%p,%p\n",p,p+3);
    
    //for( p = &a[3];p < &a[5]; ++p)
    //    printf("%4d",*p);
    //putchar('\n');向后移动

    for( p = a + 4;p > a; --p)
        *p = *(p- 1);
        *p = 0; //数组元素的移动 从后往前
        //printf("%4d",*p);
    putchar('\n');
    return 0;
}