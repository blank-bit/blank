#include <stdio.h>
#include <malloc.h>

#include "string.h"

int StrSet(String *s, char *t)
{
    int i;
    char *p = t;

    while (*p) ++p;
    s->len = p - t;

    s->ch = (char *)malloc(s->len);
    for (i = 0; i < s->len; ++i)
        s->ch[i] = t[i];
    return s->len;
}

void StrDestroy(String *s)
{
    free(s->ch);
}

int StrPrint(String *s)
{
    for (int i = 0; i < s->len; ++i)
        putchar(s->ch[i]);
    return s->len;
}

void StrCopy(String *s, String *t)
{
    for (int i = 0; i < t->len; ++i)
        s->ch[i] = t->ch[i];
    s->len = t->len;
}

// bool StrInsert(String *s, int pos, String *t)
// {
//     if (pos < 0 || pos > s->len || t->len == 0)
//         return false;

//     int mstart, mend, cend;

//     if (s->len + t->len <= MAXLEN)
//     {
//         mstart = s->len + t->len - 1;
//         mend = pos + t->len;
//         cend = mend;
//     }
//     else if (pos + t->len <= MAXLEN)
//     {
//         mstart = MAXLEN - 1;
//         mend = pos + t->len;
//         cend = mend;
//     }
//     else
//     {
//         mstart = -1;
//         mend = 0;
//         cend = MAXLEN - 1;
//     }

//     int i;
//     for (i = mstart; i >= mend; --i)
//         s->ch[i] = s->ch[i - t->len];
//     for (i = pos; i < cend; ++i)
//         s->ch[i] = t->ch[i - pos];

//     s->len += t->len;
    
//     return 0;
// }