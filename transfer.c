#include <stdio.h>
#include <string.h>

void bubble_sort(char a[][8],int len)
{
    int i,j;
    char t[8];

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
    char planet[][8] = {
        "Mecurry",
        "Venus",
        "Mars",
        "Earth",
        "Jupiter",
        "Saturn",
        "Neptune",
        "Urinas"
    };
    int i;

    bubble_sort(planet, 8);

    for(i = 0;i < 8; ++i)
        printf("%s\n",planet[i]);
    
    return 0 ;
}