#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 10
#define true 1
#define producerNum 3
#define consumerNum 4
#define sleepTime 3

typedef int semaphore;
typedef int item;
item buffer[N] = {0};
int in = 0;
int out = 0;
int proCount = 0;
char str[N][10] = {};
semaphore mutex = 1, empty = N, full = 0;
FILE *fp;

void *producer(void *a)
{
    while (true)
    {
        while (empty <= 0) //是否有空缓冲区
        {
            printf("缓冲区已满！\n");
            sleep(1);
        }
        empty--;

        while (mutex <= 0) //判断缓冲区是否在被访问
            ;
        mutex--;

        if (fscanf(fp, "%s ", str[in]) == EOF)
        {
            rewind(fp);
            fscanf(fp, "%s ", str[in]);
        }

        proCount++;
        printf("生产一个产品ID%d, 缓冲区位置为%d,内容为%s\n", proCount, in, str[in]);

        buffer[in] = proCount;
        in = (in + 1) % N;

        full++;
        mutex++;
        sleep(sleepTime);
    }
}

void *consumer(void *b)
{
    while (true)
    {
        while (full <= 0) //缓冲区是否有产品
        {
            printf("缓冲区为空！\n");
            sleep(2);
        }
        full--;

        while (mutex <= 0)
            ;
        mutex--;

        int nextc = buffer[out];
        int temp = out;

        buffer[out] = 0; //消费完将缓冲区设置为0
        out = (out + 1) % N;

        empty++;

        printf("\t\t\t\t消费一个产品ID%d,缓冲区位置为%d,内容为%s\n", nextc, out, str[temp]);

        mutex++;

        sleep(sleepTime);
    }
}

int main()
{
    fp = fopen("./data.txt", "r");
    if (fp == NULL)
        exit(1);

    pthread_t threadPool[producerNum + consumerNum];
    int i;
    for (i = 0; i < producerNum; i++)
    {
        pthread_t temp;
        if (pthread_create(&temp, NULL, producer, NULL) == -1)
        {
            printf("ERROR, fail to create producer%d.\n", i);
            exit(1);
        }
        threadPool[i] = temp;
    } //创建生产者进程放入线程池

    for (i = 0; i < consumerNum; i++)
    {
        pthread_t temp;
        if (pthread_create(&temp, NULL, consumer, NULL) == -1)
        {
            printf("ERROR, fail to create consumer%d.\n", i);
            exit(1);
        }
        threadPool[i + producerNum] = temp;
    } //创建消费者进程放入线程池

    for (i = 0; i < producerNum + consumerNum; i++)
    {
        if (pthread_join(threadPool[i], NULL) == -1)
        {
            printf("fail to recollect.\n");
            exit(1);
        }
    } //运行线程池

    fclose(fp);

    return 0;
}
