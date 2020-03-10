#include <stdio.h>
#include <stdlib.h>

char* skip_space(char* s)
{
    while(*s == ' ')++s;
    return s;
}

char* skip_word(char* s)
{
    while(*s != ' ' && *s != '\n')++s;
    return s;
}
int main()
{
    char str[128];
    char *p = str;
    int count = 0;

    fgets(p , 127 , stdin);

    while(1)
    {
        p = skip_space(p);
        if(*p == '\n') break; 
        ++count;
        *p -= 32;
        p = skip_word(p);
    }
    printf("%s\n%d words\n",str , count);
    return 0;
}