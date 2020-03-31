#include <stdio.h>

struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;

void odd_even(SeqList *L) 
{
    int i = 0 ,j = L->last - 1;
    int temp;
    while(i < j)
    {
        while(L->elem[i] % 2 != 0) i++;
        while(L->elem[j] % 2 == 0) j--;
        temp = L->elem[i];
        L->elem[i] = L->elem[j];
        L->elem[j] = temp;
    }

}

struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)
{
    Node* p , q , t;
    p = L->next;
    q = L;
    while(p->data <= mink && p)
    {
        p = p->next;
        q = q->next;
    } 
    while(p->data > mink && p->data < maxk)
    {
        t = p;
        q->next = p->next;
        p = p->next;
        free(t);
    }
}

int lnk_search(LinkList L, int k, ElemType* p_ele)
{
    Node* p , *q;
    p = q = L->next;
    int t = 0;
    while(t < k && p)
    {
        p = p->next;
        t++;
    }
    if(t != k-1) 
        return 0;
    else 
    {
        while(p)
        {
            p = p->next;
            q = q->next;
        }
        return q->data;
    }

}

struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};

typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

void lnk_merge(LinkList A, LinkList B, LinkList C) 
{
    LinkList p , q , t;
    t = C;
    q = B->next;
    p = A->next;
    while(p != NULL && q != NULL)
        if(p->data <= q->data)
            {
                t->next = p;
                t = t->next;
                p = p->next;
            }
        else 
        {
            t->next = q;
            t = t->next;
            q = q->next;
        }
    if(p)
        t->next = p;
    else 
        t->next = q;
    free(A);
    free(B);
}

#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

bool init_queue(LinkQueue* LQ)
{
    (*LQ) = (LinkQueue)malloc(sizeof(LinkQueueNode));
    if (*LQ) {
        (*LQ)->next = *LQ;
        return true;
    } else
        return false;
}

bool enter_queue(LinkQueue* LQ, ElemType x)
{
    LinkQueue p;
    p = (LinkQueue)malloc(sizeof(LinkQueueNode));
    if (p) {
        p->data = x;
        p->next = (*LQ)->next;
        (*LQ)->next = p;
        (*LQ) = p;
        return true;
    } else {
        return false;
    }
}

bool leave_queue(LinkQueue* LQ, ElemType* x)
{
    LinkQueue p;
    p = (*LQ)->next;
    LinkQueue q = p->next;
    if (p == *LQ)
        return false;
    if (q == *LQ) {
        *x = q->data;
        p->next = q->next;
        free(q);
        *LQ = p;
    } else {
        *x = q->data;
        p->next = q->next;
        free(q);
        return true;
    }
}
#include "list.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>

int compute_reverse_polish_notation(char* str)
{
    Stack S;
    init_stack(&S);
    char* p = str;
    int x, y, z, result;
    while (*p != '\0') {
        switch (*p) {
        case ' ':
            break;
        case '+':
            pop(&S, &x);
            pop(&S, &y);
            push(&S, y + x);
            break;
        case '-':
            pop(&S, &x);
            pop(&S, &y);
            push(&S, y - x);
            break;
        case '*':
            pop(&S, &x);
            pop(&S, &y);
            push(&S, y * x);
            break;
        case '/':
            pop(&S, &x);
            pop(&S, &y);
            push(&S, y / x);
            break;
        case '%':
            pop(&S, &x);
            pop(&S, &y);
            push(&S, y % x);
            break;
        default:
            push(&S, atoi(p));
            z = atoi(p);
            while (z / 10 != 0) 
            {
                p++;
                z /= 10;
            }
            break;
        }
        p++;
    }
    pop(&S, &result);
    return result;
}