#include <stdio.h>

// parameter
double average(double x, double y)
{
    return (x + y) / 2.0;
}

int main()
{
    double a,b,c;
    a = 2.3; b = 4.6;
    c = average(a,b/*实际参数，传值*/);//调用函数

    
    return 0;
}



//another

#include <stdio.h>

//prototype原型声明
double average(double x/*可省*/, double y/*可省*/);

int main()
{
    double a,b,c;
    a = 2.3; b = 4.6;
    c = average(a,b);

    
    return 0;
}

double average(double x, double y)
{
    return (x + y) / 2.0;
}

