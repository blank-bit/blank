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