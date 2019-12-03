#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE, *NODEPTR;

typedef void (*FUNPTR)(int *);

void traverse(NODEPTR l, FUNPTR callback)
{
    NODEPTR p = l;

    while (p != NULL)
    {
        callback(&p->data);
        p = p->next;
    }
}

void print(int *v) { printf("%6d", *v); }
void inc(int *v) { ++*v; }
void square(int *v) { *v *= *v; }

int main()
{
    NODE a = {1, NULL}, b = {2, NULL}, c = {3, NULL}, d = {4, NULL};
    NODEPTR head = &a;

    a.next = &b;
    b.next = &c;
    c.next = &d;

    traverse(head, print); putchar('\n');

    traverse(head, inc); traverse(head, print); putchar('\n');

    traverse(head, square); traverse(head, print); putchar('\n');

    return 0;
}