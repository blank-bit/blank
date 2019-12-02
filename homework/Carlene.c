#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x,y,i,j,h,m,n,k;
    char str1[]={" 一 二 三 四 五 六 日"};
    printf("Enter number of days in month:");
    scanf("%d",&x);
    printf("Enter starting day of the week(1=Sun, 7=Sat):");
    scanf("%d",&y);
    printf("%s",str1);
    printf("\n");

    int a;
    a = 1;
    while(a < y)
    {
        a++;
        printf("   ");
    
    }    
    
        for(i = 1;i < 9-y;i++)    
        printf("%3d",i);
        
    printf("\n");
    
    
    

    int b[3][7];
    h = 9-y;
    for (m = 0;m < 3;m++)       
        {
                for(n = 0;n < 7;n++)  
                {
                    b[m][n] = h;
                    printf("%3d",b[m][n]);
                    if(h < x)
                        h++;
                }  
                
                printf("\n"); 
        }       

    k = 30-y;
    while(k <= x)
    {
        printf("%3d",k);
        k++;
    }
    printf("\n");
    return 0;
}