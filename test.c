#include <stdio.h>

#define N 10

int main()
{
    int in = 0, out = 0;
    for (;;)
    {
        in = (in + 1) % N;
        out = (out + 1) % N;
    }
    return 0;
}