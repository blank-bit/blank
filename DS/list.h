// #pragma once

// #include "list_elemtype.h"

// #define	MAXSIZE  100   /*此处的宏定义常量表示线性表可能达到的最大长度*/

// typedef  struct
// { 
// 	ElemType  elem[MAXSIZE];  /*线性表占用的数组空间*/
// 	int       last;    /*记录线性表中最后一个元素在数组elem[ ]中的位置（下标值），空表置为-1*/
// } SeqList, LList, *LListPtr;

#pragma once

#include "list_elemtype.h"

typedef struct _node
{ 
	ElemType data;
	struct _node  * next;
} Node, *NodePtr, LList, *LListPtr;