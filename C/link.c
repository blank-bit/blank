#include <stdio.h>

typedef void (*FUNPTR)(int);//() --> 函数
FUNPTR fp;

int f(int i) {
    return 0;
}

typedef struct node
{
    int data;
    struct node * next;
} NODE, *NODEPTR;

void traverse(NODEPTR head ,FUNPTR callback)//遍历(贯穿)  回调函数：callback
{
    NODEPTR p = head;
    while(p != NULL)
    {
        //printf("%d\n", p->data);
        callback(p -> data);
        p = p -> next;
    }
}

void printX3(int v)
{
    printf("%d\n", v * 3);
}
void print(int v)
{
    printf("%d\n", v);
}
int main()
{
    NODE a = {1, NULL},b = {2, NULL},
    c = {3, NULL};
    NODEPTR head, p;

    a.next = &b;
    b.next = &c;

    head = &a;
    traverse(head, print);
    traverse(head, printX3);//调用函数

    return 0;
}