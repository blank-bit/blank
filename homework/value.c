#include<stdio.h>
int main()
{
    float value,a;
    char mark;
    printf("Enter an expression:");
    scanf("%f",&value);
    while((mark = getchar()) != '\n'){
        scanf("%f",&a);
        switch(mark){
            case '+' : value += a;break;
            case '-' : value -= a;break;
            case '*' : value *= a;break;
            case '/' : value /= a;break;
        }
    }
    printf("Value of expression:%.1f",value);

    return 0;


}