#include<stdio.h>

int main()
{
    #define N 10
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int low = 0, heigh = N - 1, mid;
    int key;

    scanf("%d",&key);
    
    while(low <= heigh)
    {
        mid = (low + heigh) / 2;
        if (a[mid] == key) 
        {
            printf("key = %d",mid);
            break;//found
        }
        else if(a[mid] < key)
        low = mid + 1;
        else 
        heigh = mid - 1;
    }
    
    if (low > heigh)
    printf("Not found\n");
    
    return 0;
}