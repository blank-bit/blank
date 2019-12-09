#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char a[21] , max[21], min[21];
    int i = 0, j = 0 , l;

    gets(a);
    l = strlen(a);
    strcpy(min , a);
    strcpy(max , a);

    while(l != 4)
    {
        gets(a);
        l = strlen(a);

            if(strcmp(a,max) > 0)
            {
                strcpy(max , a);
            }
            else if(strcmp(min , a) > 0)
            {
                strcpy(min , a);
            }
        }

    printf("%s\n",a);
    printf("%s , %s",max , min);
    
    return 0 ;
}