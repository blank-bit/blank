#include <stdio.h>
#include <malloc.h>

#include "list.h"
#include "list_interface.h"

// void InitList(LListPtr *L)
// {
//     (*L)->last = -1;
// }

// bool InsList(LListPtr L, int i, ElemType e)
// {
//     if (i < 1 || i > L->last + 2) return false;

//     for (int j = L->last; j >= i - 1; --j)
//         L->elem[j + 1] = L->elem[j];
//     L->elem[i - 1] = e;
//     ++L->last;

//     return true;
// }

// bool DelList(LListPtr L, int i, ElemType *e)
// {
//     return true;
// }

// void traverse(LListPtr L, CALLBACK f)
// {
//     for (int i = 0; i <= L->last; ++i)
//         f(&L->elem[i]);
// }


//new
void InitList(LListPtr *L)
{
    (*L) = (NodePtr)malloc(sizeof(Node)); //生成头结点
    (*L)->next = NULL; //头结点的指针域为空
}

bool InsList(LListPtr L, int i, ElemType e)
{
	NodePtr p = L, q;
	int k = 1;
    
    /*从"头"开始，查找第i-1个结点*/
	while (p != NULL && k < i)  /*表未查完且未查到第i-1个时重复，找到p指向第i-1个*/ 
	{ 
		p = p->next;
		++k; 
	}
    
	if (p == NULL && k < i)   /*如当前位置p为空表已找完还未数到第i个，说明插入位置不合理*/ 
	{ 
		printf("插入位置不合理!");
		return false;
	}

	q = (NodePtr)malloc(sizeof(Node));   /*申请一个新的结点S */
	q->data = e;                       /*值e置入s的数据域*/
	q->next = p->next;				/*修改指针，完成插入操作*/
	p->next = q;
	
    return true;
}

void traverse(LListPtr L, CALLBACK f)
{
    NodePtr p = L->next;
	while (p != NULL)
	{
        f(&p->data);
        p = p->next;
	}
}

void DestroyList(LListPtr L)
{
    NodePtr p = L, q;
	while (p != NULL)
	{
        q = p;
		p = p->next;
		free(q);
	}
}

