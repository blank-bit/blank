#include <stdio.h>

#include "list.h"
#include "list_interface.h"

void InitList(LListPtr *L)
{
    (*L) = (NodePtr)malloc(sizeof(Node)); //生成头结点
    (*L)->next = NULL; //头结点的指针域为空
}

//请根据教材自行完成下列函数的编码
bool InsList(LListPtr L, int i, ElemType e)
{
    return true;
}

bool DelList(LListPtr L, int i, ElemType *e)
{
    return true;
}

void traverse(LListPtr L, CALLBACK f)
{
}