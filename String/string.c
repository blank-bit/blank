#include <stdio.h>

#include "string.h"

int StrSet(String *s, char *t)
{
    int i;

    for(i = 0; i < MAXLEN && t[i] != '\0'; ++i)
        s->ch[i] = t[i];
    return s->len = i;
}

int StrPrint(String *s)
{
    for(int i= 0;i < s->len; ++i)
        putchar(s->ch[i]);
    return s->len;
}

void StrCopy(String *s, String *t)
{
    for (int i = 0; i < t->len;++i)
        s->ch[i] = t->ch[i];
    s->len = t->len;
}

