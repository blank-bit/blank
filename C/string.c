#include<stdio.h>

int main()
{
    //char a[] = {'a' ,'b' ,'c' ,'\0'};//有效三字符，存储四字符
    //char b[] = "abc";//数组复制字符串,字符串位于常量，数组b中为复制品，b为变量
                     //"abc"为指针
    //char *p = b;//指针直接指向字符串,*p指向字符串首字符地址
                    //置于常量内存 : const memory
    //*p = 'A';//改首字符
    //a[0] = b[0] = 'A';

    char b[1024];
    char *p;//p要有明确指向，否则为野指针

    p = b;

    //scanf("%s",p);//不能有空格，否则直接结束
    fgets(p , 1023, stdin);//以回车为结尾,f:文件file
                        // ， 最大字符数量 ， 文件名(标准输入)
    fputs(p , stdout);// ， 标准输出/标准错误
    
    //printf("%s\n",p);

    return 0;
}

//stdout
//./string > out.txt
// 输入
//cat out.txt

// fputs (p , stderr);
//./string < data.txt (文件名)