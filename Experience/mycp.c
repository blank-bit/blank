#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#include <sys/stat.h>
#include <dirent.h>

void copy_file(const char *src, const char *dest);
void copy_directory(const char *src, const char *dest, const char *name);

int main(int argc, char *argv[])
{
	int status_out = -1;
	if (argc < 3)
	{
		perror("argument error ... ");
		return -1;
	}

	struct stat state;
	stat(argv[argc - 1], &state);

	if (S_ISDIR(state.st_mode))
		status_out = 1;
	else if (S_ISREG(state.st_mode))
		status_out = 0;

	int i;
	char buffer[256] = {0};
	for (i = 1; i < argc - 1; i++)
	{
		printf("argv[%d]:%s\n", i, argv[i]);
		printf("argv[%d]:%s\n", argc - 1, argv[argc - 1]);
		stat(argv[i], &state);
		if (S_ISREG(state.st_mode))
		{
			if (status_out == 1)
			{
				sprintf(buffer, "%s/%s", argv[argc - 1], argv[i]);

				printf("buffer:%s\n", buffer);
			}
			else
			{
				sprintf(buffer, "%s", argv[argc - 1]);
				printf("buffer:%s\n", buffer);
			}
			copy_file(argv[i], buffer);
			continue;
		}
		if (S_ISDIR(state.st_mode))
		{

			copy_directory(argv[i], argv[argc - 1], argv[i]);
			continue;
		}
	}

	return 0;
}

void copy_file(const char *src, const char *dest)
{
	int src_fd;
	int dest_fd;

	src_fd = open(src, O_RDONLY);
	if (-1 == src_fd)
	{
		perror("mycy srcfile error");
		return;
	}
	char ch;
	dest_fd = open(dest, O_CREAT | O_WRONLY | O_EXCL, 0777);
	if (dest_fd < 0)
	{

		printf("Over write ? Y/N\n");
		ch = getchar();
		if ((ch == 'Y') || (ch == 'y'))
		{
			close(dest_fd);
			dest_fd = open(dest, O_WRONLY | O_TRUNC);
		}
		else
		{
			return;
		}
	}

	char buffer[10] = {0};
	int ret;
	while (1)
	{
		ret = read(src_fd, buffer, 10);
		write(dest_fd, buffer, ret);
		if (ret != 10)
			break;
	}

	close(dest_fd);
	close(src_fd);
	return;
}

void copy_directory(const char *src, const char *dest, const char *name)
{
	char buffer[265] = {0};
	char tmpbuffer[512] = {0};
	char tmpbuffer1[512] = {0};

	sprintf(buffer, "%s", dest);
	printf("buffer:%s\n", buffer);

	int ret;
	struct stat state;
	DIR *dir = NULL;
	struct dirent *entry = NULL;

	ret = stat(buffer, &state);
	if (ret == -1)
	{

		ret = mkdir(buffer, 0777);
		printf("ret:%d buffer:%s\n", ret, buffer);
		dir = opendir(src);
		if (dir == NULL)
		{
			perror("open dir error");
			return;
		}

		while (1)
		{
			entry = readdir(dir);
			if (NULL == entry)
				break;
			if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0))
				continue;
			sprintf(tmpbuffer, "%s/%s", buffer, entry->d_name);
			sprintf(tmpbuffer1, "%s/%s", src, entry->d_name);
			stat(tmpbuffer1, &state);
			if (S_ISREG(state.st_mode))
			{
				copy_file(tmpbuffer1, tmpbuffer);
			}
			if (S_ISDIR(state.st_mode))
			{
				copy_directory(tmpbuffer1, buffer, entry->d_name);
				printf("*********** %s   ->  %s \n", tmpbuffer1, buffer);
			}
		}
	}
}
