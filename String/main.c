#include <stdio.h>

#include "string.h"

int main()
{
    String s, t;

    StrSet(&s, "Hollo, world!");
    StrSet(&t, "Aloha!");

    StrPrint(&s);
    putchar('\n');

    StrPrint(&t);
    putchar('\n');

    StrCopy(&s, &t);
    StrPrint(&t);
    putchar('\n');

    return 0;
}