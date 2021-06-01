/*********************************************
 @Author       : Mr.Wang
 @Date         : 2021-06-01 16:56:43
 @FilePath     : /1.c
 @Description  : message
*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
int copy(char *in, char *out);
int copydir(char *in1, char *out1);
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("error");
        return -1;
    }
    struct stat buf;
    struct stat buf1;
    if (lstat(argv[1], &buf) < 0)
    {
        printf("error");
        return -1;
    }
    if (lstat(argv[1], &buf1) < 0)
    {
        printf("error");
        return -1;
    }
    if (S_ISREG(buf1.st_mode))
    {
        copy(argv[1], argv[2]);
        return 0;
    }
    if (S_ISDIR(buf1.st_mode))
    {
        copydir(argv[1], argv[2]);
        return 0;
    }
}
int copy(char *in, char *out)
{
    char buffer[1024];
    int fd = open(in, O_RDONLY);
    int fd1 = open(out, O_WRONLY | O_CREAT);
    int len = read(fd, &buffer, sizeof(buffer));
    write(fd1, buffer, len);
    close(fd);
    close(fd1);
    return 0;
}
int copydir(char *in1, char *out1)
{
    mkdir(out1, 0777);
    struct dirent *srcdirent = NULL;
    char newsrcPath[4096];
    char newdestPath[4096];
    DIR *srcdir = opendir(in1);
    while (srcdirent = readdir(srcdir))
    {
        if (!strcmp(srcdirent->d_name, ".") || !strcmp(srcdirent->d_name, ".."))
            continue;
        else
        {
            memset(newsrcPath, 0, 1024);
            memset(newdestPath, 0, 1024);
            strcpy(newsrcPath, in1);
            strcat(newsrcPath, "/");
            strcat(newsrcPath, srcdirent->d_name);
            strcpy(newdestPath, out1);
            strcat(newdestPath, "/");
            strcat(newdestPath, srcdirent->d_name);

            if ((srcdirent->d_type & DT_DIR) == DT_DIR)
            {
                printf("%s\n", newdestPath);
                printf("%s\n", newsrcPath);
                copydir(newsrcPath, newdestPath);
            }
            else
            {
                printf("22");
                copy(newsrcPath, newdestPath);
            }
        }
    }
    return 0;
}
