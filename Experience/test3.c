#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 10
#define true 1
#define producerNum 100
#define consumerNum 3
#define sleepTime 1

typedef int item;

int in = 0, out = 0, proCount = 0;
char str[N][11] = {};
sem_t mutex, empty, full;
item buffer[N] = {0};
FILE *fp;

void *producer(void *a)
{
    while (true)
    {
        if (sem_wait(&empty) == -1) //是否有空缓冲区
        {
            printf("缓冲区已满！\n");
            sleep(1);
        }

        sem_wait(&mutex);

        if (fscanf(fp, "%s ", str[in]) == EOF)
        {
            rewind(fp);
            fscanf(fp, "%s ", str[in]);
        }

        proCount++;
        printf("生产一个产品ID%d, 缓冲区位置为%d,内容为%s\n", proCount, in, str[in]);

        buffer[in] = proCount;
        in = (in + 1) % N;

        sem_post(&full);
        sem_post(&mutex);
        sleep(sleepTime);
    }
}

void *consumer(void *b)
{
    while (true)
    {
        if (sem_wait(&full) == -1) //缓冲区是否有产品
        {
            printf("缓冲区为空！\n");
            sleep(2);
        }

        sem_wait(&mutex);

        int nextc = buffer[out];
        int temp = out;

        buffer[out] = 0; //消费完将缓冲区设置为0
        out = (out + 1) % N;

        sem_post(&empty);

        printf("\t\t\t\t\t消费一个产品ID%d,缓冲区位置为%d,内容为%s\n", nextc, out, str[temp]);

        sem_post(&mutex);

        sleep(sleepTime);
    }
}

int main()
{
    fp = fopen("./data.txt", "r");
    if (fp == NULL)
        exit(1);

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);

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
            printf("ERROR, fail to recollect.\n");
            exit(1);
        }
    } //运行线程池

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    fclose(fp);

    return 0;
}
