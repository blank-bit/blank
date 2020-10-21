#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define N 10
int main()
{
    char a[N][N];
    int i = 0,j = 0,num,x = 1 ;
    const char star = 'A';

    /*******************
    for(i = 0;i < N ;i++)
    {
        for(j = 0;j < N;j++)
        a[i][j] = '.';
    }
    *******************/
    memset(a,'.',100);

    a[0][0] = star ;
    srand((int)time(0));
    while(1){
        num = rand() % 4;
        switch(num){
            case 0: //向上走
            if ((i - 1) >= 0) {
                if (a[i - 1][j] == '.') {
                    a[i - 1][j] = star + x;
                    ++x;
                    i -= 1;
                }
            }
            break;
        case 1: //向下走
            if ((i + 1) < N) {
                if (a[i + 1][j] == '.') {
                    a[i + 1][j] = x + star;
                    ++x;
                    i += 1;
                }
            }
            break;
        case 2: //向左走
            if ((j - 1) >= 0) {
                if (a[i][j - 1] == '.') {
                    a[i][j - 1] = x + star;
                    ++x;
                    j -= 1;
                }
            }
            break;
        case 3: //向右走
            if ((j + 1) < N) {
                if (a[i][j + 1] == '.') {
                    a[i][j + 1] = x + star;
                    ++x;
                    j += 1;
                }
            }
            break;
        }
        if (x == 26 || ((a[i + 1][j] != '.') && (a[i - 1][j] != '.') && (a[i][j + 1] != '.') && (a[i][j - 1] != '.')))
            break; //数字尽头结束和封住走过的路。
        if ((i - 1 < 0) && (j - 1 < 0) && (a[i + 1][j] != '.') && (a[i][j + 1] != '.'))
            break; //封左上角
        if ((i + 1 > N - 1) && (j - 1 < 0) && (a[i + 1][j] != '.') && (a[i][j + 1] != '.'))
            break; //封左下角
        if ((i - 1 < 0) && (j + 1 > N - 1) && (a[i + 1][j] != '.') && (a[i][j + 1] != '.'))
            break; //封右上角
        if ((i + 1 > N - 1) && (j + 1 > N - 1) && (a[i + 1][j] != '.') && (a[i][j + 1] != '.'))
            break; //封右下角
        if ((i - 1 < 0) && (a[i + 1][j] != '.') && (a[i][j - 1] != '.') && (a[i][j + 1] != '.'))
            break; //封上边框
        if ((i + 1 > N - 1) && (a[i - 1][j] != '.') && (a[i][j - 1] != '.') && (a[i][j + 1] != '.'))
            break; //封下边框
        if ((j - 1 < 0) && (a[i - 1][j] != '.') && (a[i + 1][j] != '.') && (a[i][j + 1] != '.'))
            break; //封左边框
        if ((j + 1 > N - 1) && (a[i - 1][j] != '.') && (a[i + 1][j] != '.') && (a[i][j - 1] != '.'))
            break; //封右边框
    }

    for(i = 0;i < N ;i++)
    {
        for(j = 0;j < N;j++)
            printf("%c",a[i][j]);
        putchar('\n');
    }
    return 0;
}