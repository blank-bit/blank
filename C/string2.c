#include <stdio.h>

size_t strlen(char *s)// 有效 字符串长度 //size_t 无符号长整形
{
    // size_t i = 0;
    // while(*s++)//*s != '\0' ==> 1 (*s --> != 0 )
    
    // ++i;
    //         //++s; //指针指向下一个字符
    //  return i;
    char *t = s;
    while (*t++);
    return t - s - 1;
}

void strcpy(char *dest, const char *src)//后拷贝到前
{
    //while(*src) *dest++ = *src++;
    // {
    //      *dest = *src;
    //      ++src;
    //      ++dest;

    // }
    //*dest = '\0';

    while((*dest++ = *src++));
}

int main()
{
    char *p = "1234567890";
    char *q;
    char buf[1024];

    q = buf;
    strcpy(q,p);

    //printf("%ld\n", strlen(p));//sizeof(p) p占字节大小
    printf("%s\n",q);

    return 0;
}