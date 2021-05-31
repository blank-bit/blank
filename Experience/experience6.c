#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

//缓冲区大小
#define BUF_SIZE 1024
#define PATH_SIZE 1024

//0664权限:所有者和组成员具有读写的权限，其他人只有读权限
#define FILE_MODE 0664
#define DIR_MODE 0664

void deal_dir(const char *, const char *);  //处理目录
void deal_copy(const char *, const char *); //处理文件

int fd[2] = {0};

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("too few or lost parameter!\n");
        exit(EXIT_FAILURE);
    }

    struct stat get_message;
    int ret_stat = stat(argv[1], &get_message);
    if (ret_stat == -1)
        printf("error");

    if (S_ISDIR(get_message.st_mode))
        deal_dir(argv[1], argv[2]); //如果argv[1]是目录则按目录递归处理
    else
    { //否则按照文件直接复制
        if (strcmp(argv[1], argv[2]) == 0)
        {
            printf("The same filename of parameter is error!\n");
            exit(EXIT_FAILURE);
        }
        deal_copy(argv[1], argv[2]);
    }

    return 0;
}

void deal_dir(const char *old_path, const char *new_path)
{
    DIR *ret_opdir = opendir(old_path); //打开目录
    DIR *ret_opdir_new = opendir(new_path);
    if (ret_opdir == NULL)
        printf("error");
    struct dirent *ret_redir;

    char buf_old[PATH_SIZE] = {};
    char buf_new[PATH_SIZE] = {};

    char buf_oldfile[PATH_SIZE] = {};
    char buf_newfile[PATH_SIZE] = {};

    //获取源文件完整路径与目标位置完整路径,分别存入buf_old与buf_new中
    char buf[PATH_SIZE] = {};
    getcwd(buf, PATH_SIZE); //获取当前路径
    chdir(old_path);
    getcwd(buf_old, PATH_SIZE); //获取source的绝对路径
    strcat(buf_old, "/");
    chdir(buf);
    if (ret_opdir_new == NULL)
    {
        int ret_mkdir = mkdir(new_path, DIR_MODE); //创建子目录
        if (ret_mkdir == -1)
            printf("error");
    }
    chdir(new_path);
    getcwd(buf_new, PATH_SIZE);
    strcat(buf_new, "/");

    while ((ret_redir = readdir(ret_opdir)))
    {
        if (!strcmp(ret_redir->d_name, ".") || !strcmp(ret_redir->d_name, ".."))
            continue;
        else
        {
            //清空source与target的带文件名的绝对路径缓冲区
            memset(buf_oldfile, 0, PATH_SIZE);
            memset(buf_newfile, 0, PATH_SIZE);
            //将source的缓冲区更新为最新读到的source文件
            strcpy(buf_oldfile, buf_old);
            strcat(buf_oldfile, ret_redir->d_name);

            strcpy(buf_newfile, buf_new);
            strcat(buf_newfile, ret_redir->d_name);

            if ((ret_redir->d_type & DT_REG) == DT_REG) //如果读到的文件是普通文件则复制
                deal_copy(buf_oldfile, buf_newfile);
            else if ((ret_redir->d_type & DT_DIR) == DT_DIR) //如果读到的是目录则递归处理目录
                deal_dir(buf_oldfile, buf_newfile);
        }
    }
}

void deal_copy(const char *old_file, const char *pathname)
{
    struct stat get_message;
    int ret_stat = stat(pathname, &get_message);
    if (ret_stat == -1 && errno != ENOENT) //文件信息读取失败，并且不是因为无该文件造成的
        printf("error");

    fd[0] = open(old_file, O_RDONLY); //打开source文件
    if (fd[0] == -1)
        printf("error");
    fd[1] = open(pathname, O_CREAT | O_TRUNC | O_RDWR, FILE_MODE); //创建并打开target文件
    if (fd[1] == -1)
        printf("error");

    //进行source的读与对应的target的写(复制)
    char buf[BUF_SIZE] = {};
    int ret_read, ret_write;
    while ((ret_read = read(fd[0], buf, BUF_SIZE)) > 0)
    { //读到EOF时返回0结束
        ret_write = write(fd[1], buf, strlen(buf));

        if (ret_write == -1)
            printf("error");
    }

    close(fd[0]);
    close(fd[1]);
}