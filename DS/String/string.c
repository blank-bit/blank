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

bool StrInsert(String *s, int pos, String *t)
{
    if (pos < 0 || pos > s->len || t->len == 0)
        return false;

    int mstart, mend, i, cend;

    if(s->len + t->len <= MAXLEN)
    {
        mstart = s->len + t->len - 1;
        mend = pos + t->len;
        cend = pos + t->len;//mend
    }
    else if (pos + t->len <= MAXLEN)
    {
        mstart = MAXLEN - 1;
        mend = pos + t->len;
        cend = pos + t->len;//mend
    }
    else
    {
        mstart = -1;
        mend = 0;
        cend = MAXLEN - 1;
    }

    for (i = mstart;i >= mend; --i)
        s->ch[i] = s->ch[i - t->len];
    for(i = pos; i < cend; ++i)
        s->ch[i] = t->ch[i - pos];
        
    s->len += t->len;

    return true;
}