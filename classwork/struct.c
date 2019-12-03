#include <stdio.h>

typedef struct 
{
    int a;
    char c;
} foo, *fooPTR;

void boo(foo y)
{
    y.a = 2;
    y.c = 'B';
}

void goo(fooPTR y)
{
    y->a = 2;
    y->c = 'B';
}

int main()
{
    foo x = {1, 'A'};
    fooPTR p = &x;//foo *p
    
    // boo(x);传值
    goo(p);//传地址
    printf("%d,%c\n", p->a,p->c);//"->" 结构中读地址

    return 0;
}