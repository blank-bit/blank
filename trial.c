#include <stdio.h>
#include <string.h>

void bubble_sort(char a[][20],int len)
{
    int i,j;
    char t[20];

    for(i = 0;i < len - 1;++i)
        for(j = 0;j< len -i -1;++j)
            if(strcmp(a[j] , a[j+1]) > 0)
            {//block
                strcpy(t , a[j]);//效率低，可扩大定义范围
                strcpy(a[j] , a[j+1]);
                strcpy(a[j+1] , t);//转换值
            }
}

int main()
{
    char a[][20] = {0};
    int i = 0, j = 0;

    
    while((a[i][j] = getchar()) != '\n')
    {
        j++;
    }
    bubble_sort(planet, 8);

    for(i = 0;i < 8; ++i)
        printf("%s\n",planet[i]);
    
    return 0 ;
}