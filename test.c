/*********************************************
 @Author       : Mr.Wang
 @Date         : 2021-04-26 14:39:34
 @FilePath     : /test.c
 @Description  : message
*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    pid_t p1, p2;
    int fd[2];
    char child1[] = "Child process 1 is sending a message!";
    char child2[] = "Child process 2 is sending a message!";
    int len1 = strlen(child1);
    int len2 = strlen(child2);

    if (pipe(fd) == -1)
    {
        printf("error");
        return 1;
    }

    if ((p1 = fork()) == -1)
    {
        printf("failed to fork");
    }
    else if (p1 == 0)
    {
        close(fd[0]);
        write(fd[1], child1, strlen(child1) + 1);
        fprintf(stderr, "[%ld]:child1 put {%.*s} into pipe\n", (long)getpid(), len1, child1);
        exit(0);
    }

    if ((p2 = fork()) == -1)
    {
        printf("failed to fork");
    }
    else if (p2 == 0)
    {
        close(fd[0]);
        sleep(1);
        write(fd[1], child2, strlen(child2) + 1);
        fprintf(stderr, "[%ld]:child2 put {%.*s} into pipe\n", (long)getpid(), len2, child2);
        exit(0);
    }
    sleep(2);
    close(fd[1]);
    len1 = read(fd[0], child1, strlen(child1) + 1);
    len2 = read(fd[0], child2, strlen(child2) + 1);
    fprintf(stderr, "[%ld]:father read data1 {%.*s}\n              read data2 {%.*s}\n", (long)getpid(), len1, child1, len2, child2);
    return 0;
}
