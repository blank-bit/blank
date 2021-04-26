/*********************************************
 @Author       : Mr.Wang
 @Date         : 2021-04-26 10:43:09
 @FilePath     : /Experience/experience3.c
 @Description  : 操作系统实验3——基于管道的进程间数据传输
*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define BUFSIZE 45

int main()
{
    int fd[2];
    int bytesin1, bytesin2;
    pid_t childpid1, childpid2;

    char bufin1[BUFSIZE] = "Child process 1 is sending a message!"; //写入
    char bufin2[BUFSIZE] = "Child process 2 is sending a message!";

    char bufout1[BUFSIZE]; //读出
    char bufout2[BUFSIZE];

    if (pipe(fd) == -1) //创建管道
    {
        perror("Failed to create the pipe");
        return 1;
    }

    bytesin1 = strlen(bufin1); //写入的字节长度
    bytesin2 = strlen(bufin2);
    if ((childpid1 = fork()) == -1) //创建子进程
    {
        perror("Failed to fork");
        return 1;
    }
    else if (childpid1 == 0) //在子进程中
    {
        close(fd[0]);                             //关闭读端
        write(fd[1], bufin1, strlen(bufin1) + 1); //将bufin中数据写入管道
        fprintf(stderr, "[%ld]:Child1 put {%.*s} into pipe.\n", (long)getpid(), bytesin1, bufin1);
        exit(0);
    }

    if ((childpid2 = fork()) == -1) //创建子进程
    {
        perror("Failed to fork");
        return 1;
    }
    else if (childpid2 == 0) //在子进程中
    {
        close(fd[0]); //关闭读端
        sleep(1);
        write(fd[1], bufin2, strlen(bufin2) + 1);
        fprintf(stderr, "[%ld]:Child2 put {%.*s} into pipe.\n", (long)getpid(), bytesin2, bufin2);
        exit(0);
    }

    sleep(2);
    close(fd[1]);                                        //关闭写端
    bytesin1 = read(fd[0], bufout1, strlen(bufin1) + 1); //读取数据，存入bufout
    bytesin2 = read(fd[0], bufout2, strlen(bufin2) + 1);

    fprintf(stderr, "[%ld]:Father read data1 is {%.*s}\n", (long)getpid(), bytesin1, bufout1);
    fprintf(stderr, "[%ld]:Father read data2 is {%.*s}\n", (long)getpid(), bytesin2, bufout2);

    return 0;
}
