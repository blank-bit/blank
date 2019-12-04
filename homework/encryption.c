#include<stdio.h>
#include <string.h>
//加密
int main()
{
    char a[32],b[32];
    char *p , *t;
    p = a;
    t = b;
    int i , j;

    printf("Enter message to be encrypted:");
    gets(a);

    j = strlen(a);

    printf("Enter shift amount (1-25):");
    int x;
    scanf("%d",&x);
    
    for(i = 0;i < j + 1;i++)
    {
        if((a[i] < 91 && a[i] > 64) || (a[i] < 123 && a[i] > 96))
        {  
            if(a[i] < 91 - x && a[i] > 64 )
            a[i] += x ;
            else if(a[i] < 91 - x && a[i] > 64 )
            a[i] = a[i] + x - 26;
            else if (a[i] >= 91 - x && a[i] < 91 )
            a[i] = a[i] - 26 + x;
            else if (a[i] < 123 - x && a[i] > 96)
            a[i] += x ;
            else if(a[i] >= 123 - x && a[i] > 96 && a[i] < 123)
            a[i] = a[i] - 26 + x;
        }
        else a[i] = a[i];
    }

    for(i = 0;i < j + 1; i++)
    printf("%c",a[i]);
    
    return 0;
}