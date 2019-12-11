#include <stdbool.h> /* C99 only */
#include <stdio.h> //5.1栈
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;

void stack_overflow(void)
{
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

    //return是语言级别的，它表示了调用堆栈的返回；
    //而exit是系统调用级别的，它表示了一个进程的结束
    //exit函数是退出应用程序，删除进程使用的内存空间

void stack_underflow(void)
{
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char ch)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = ch;
}

char pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];

    return '\0'; /* prevents compiler warning due to stack_underflow() call */
}

int main()
{
    return 0;
}