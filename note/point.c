#include<stdio.h>

int main()
{
    int i = 1, j;
    int *p, *q = &j;//初始化 要先有j
    

    p = &i; //赋值
            //i的地址，非i的值 i的地址是1000，则p=1000
            //p = &j 错误；类型赋值出错 基类型不同 //double j = 2.3;
            //q = p ;//赋值，i的地址，指针共享
    
    *q = *p;//j = i
    // *q 无指向 野指针赋值 ==> 内存访问错误 *q

    //printf("%d,%d\n",sizeof(p),sizeof(long));
    //十六进制数 sizeof运算符 非函数 计算字节大小

    //i = 2;//==> *p = 2;  i = *p
    //++*p; -fsanitize=address
    printf("%d,%d\n",i,*p);
    return 0;
}