#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b[10] = { 0 };
    long int i,h,j;
    printf("Enter a number:");
    
    scanf("%ld", &i);
    printf("Digit:       0 1 2 3 4 5 6 7 8 9\n");

    while (i > 0) {
        h = i % 10;
        b[h] += 1;
        i /= 10;
    }
    printf("Occurrences:");
    for (j = 0; j < 10; j++)
        printf("%2d", b[j]);
        printf("\n");
    return 0;
}
