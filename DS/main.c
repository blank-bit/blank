#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "list_interface.h"

void print(ElemType *e)
{
    printf("%4d", *e);
}

ElemType reverse_i(LListPtr L, int i)
{
    Nodeptr p , q;
    int k;

    for(k = 1, p = L; k < i; ++i , p = p->next);
    for(q = L; p != NULL; p = p->next, q = q->next);

    return q->data;
}

// int main()
// {
//     LList list, *L = &list;

//     InitList(&L);
    
//     for (int i = 1; i < 10; ++i)
//         InsList(L, i, i + 10);

//     traverse(L, print);
//     printf("\n");

//     return 0;
// }

int main()
{
    LListPtr list;

    InitList(&list);
    
    for (int i = 1; i < 10; ++i)
        InsList(list, i, i + 10);

    traverse(list, print);
    printf("\n");

    printf("%d\n", reverse_i(list, 3));

    DestroyList(list);

    return 0;
}
