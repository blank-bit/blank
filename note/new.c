#include<stdio.h>

int f()
{
    static int i = 0;//初始化一次，记忆i的值 静态变量  延长生命期 作用域不改变
    ++i;
    return i;
}

//static int i; //定义开始有作用域  限制作用域，只在本程序有用

int g()
{
    int i = 0;
    ++i;
    return i;
}

int main()
{
    printf("%d,%d\n",f(),g());
    f();g();
    printf("%d,%d\n",f(),g());

    return 0;
}
