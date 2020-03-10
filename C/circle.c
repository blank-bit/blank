#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.1415926
//const double PI = 3.1415926

// struct _circle
// {
//     double x,y ;
//     double r;
// }
// typedef struct _circle circle;//alias
//typedef old_type new_type;
//typedef int A[5];


typedef struct 
{
    double x,y ;
    double r;
} circle;//定义类型，不是变量   不占内存

double area(circle *c)
{
    return c->r * c->r * PI;//(*c).r <==> c->r
}

circle make_circle()
{
    circle t;

    t.x = rand() % 100;
    t.y = rand() % 100;
    t.r = rand() % 10;

    return t;

}

int main()
{
    int i;
    circle c;//占内存

    // c.x = 1.0;//成员选择运算符
    // c.y = 1.0;
    // c.r = 1.0;
    // printf("%lf\n",area(c.r));
    
    srand(time(NULL));

    for(i = 0;i < 5 ; i++)
    {
        c = make_circle();
        printf("%lf\n",area(c));
    }
    return 0;
}