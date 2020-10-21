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

#include <stdio.h>
#include <stdlib.h>
#include "dsstring.h" //请不要删除，否则检查不通过

int str_compare(const char* ptr1, const char* ptr2)
{
    while(ptr1 && ptr2)
    {
        if(ptr1 == ptr2 || ptr1)
    }

}

#define BLOCK_SIZE 4    // 可由用户定义的块大小
#define BLS_BLANK '#'   // 用于空白处的补齐字符

typedef struct _block {
    char ch[BLOCK_SIZE];    //块的数据域
    struct _block *next;    //块的指针域
} Block;

typedef struct {
    Block *head;        // 串的头指针
    Block *tail;        // 串的尾指针
    int len;            // 串的当前长度
} BLString;

//字符串初始化函数：
void blstr_init(BLString *T) {
    T->len = 0;
    T->head = NULL;
    T->tail = NULL;
}

#include <stdlib.h>
#include <stdio.h>
#include "dsstring.h" // 请不要删除，否则检查不通过

bool blstr_substr(BLString src, int pos, int len, BLString *sub) 
{
    if (src.len == 0) return false;
    

}

bool path(BiTNode* root, BiTNode* node, Stack* s)
{
    BiTree T = root, p;
    if (T == NULL || node == NULL || !is_empty(s))
        return false;
    while (T || !is_empty(s)) {
        while (T) {
            push(s, T);
            if (T == node)
                return true;
            T = T->left;
        }
        top(s, &T);
        if (!T->right || T->right == p) {
            p = T;
            pop(s, &T);
            T = NULL;
        } else
            T = T->right;
    }
    return false;
}

BiTNode* nearest_ancestor(BiTree root, BiTNode* p, BiTNode* q)
{
    Stack A, B;
    init_stack(&A);
    init_stack(&B);
    path(root, p, &A);
    path(root, q, &B);
    int i;
    for (i = 0; i <= A.top && i <= B.top && A.elem[i] == B.elem[i]; ++i)
        ;
    return A.elem[i - 1];
}


//同步测试