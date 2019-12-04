#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// void bubble_sort(char a[][20],int len)
// {
//     int i,j;
//     char t[20];

//     for(i = 0;i < len - 1;++i)
//         for(j = 0;j< len -i -1;++j)
//             if(strcmp(a[j] , a[j+1]) > 0)
//             {//block
//                 strcpy(t , a[j]);//效率低，可扩大定义范围
//                 strcpy(a[j] , a[j+1]);
//                 strcpy(a[j+1] , t);//转换值
//             }
// }

int main()
{
    char a[20] , max[20], min[20];
    int i = 0, j = 0 , l;

    gets(a);
    l = strlen(a);
    min[20] = max[20] = a[20];

    while(l != 4)
    {
        gets(a);
        l = strlen(a);

        for(j = 0;j < 20; j++)
        {
            if(strcmp(a[j],max[j]) > 0)
            {
                strcpy(max[j] , a[j]);
            }
            else if(strcmp(min[j] , a[j]) > 0)
            {
                strcpy(min[j] , a[j]);
            }
        }
    }


    printf("%s , %s",max , min);
    
    return 0 ;
}