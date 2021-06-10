/*********************************************
 @Author       : Mr.Wang
 @Date         : 2021-04-19 21:09:01
 @FilePath     : /Experience/experience1.c
 @Description  : 操作系统实验1
*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

sem_t chopsticks[N];

int philosophers[N] = {0, 1, 2, 3, 4};

void *philosopher(void *arg)
{
    int i = *(int *)arg;
    int left = i;
    int right = (i + 1) % N;

    char str;
    switch (i)
    {
    case 0:
        str = 'A';
        break;
    case 1:
        str = 'B';
        break;
    case 2:
        str = 'C';
        break;
    case 3:
        str = 'D';
        break;
    case 4:
        str = 'E';
        break;
    }

    while (1)
    {
        if (i % 2 == 0)
        {
            printf("Philosopher %c is thinking.\n", str);
            sleep(3);

            sem_wait(&chopsticks[right]);
            printf("Philosopher %c fetches chopstick %d\n", str, right + 1);
            sem_wait(&chopsticks[left]);
            printf("Philosopher %c fetches chopstick %d\n", str, left + 1);
            printf("Philosopher %c is eating.\n", str);
            sleep(3);
            sem_post(&chopsticks[left]);
            printf("Philosopher %c release chopstick %d\n", str, left + 1);
            sem_post(&chopsticks[right]);
            printf("Philosopher %c release chopstick %d\n", str, right + 1);
        }

        else
        {
            printf("Philosopher %c is thinking.\n", str);
            sleep(3);

            sem_wait(&chopsticks[left]);
            printf("Philosopher %c fetches chopstick %d\n", str, left + 1);
            sem_wait(&chopsticks[right]);
            printf("Philosopher %c fetches chopstick %d\n", str, right + 1);
            printf("Philosopher %c is eating.\n", str);
            sleep(3);
            sem_post(&chopsticks[left]);
            printf("Philosopher %c release chopstick %d\n", str, left + 1);
            sem_post(&chopsticks[right]);
            printf("Philosopher %c release chopstick %d\n", str, right + 1);
        }
    }
}

int main()
{

    pthread_t philo[N];

    for (int i = 0; i < N; i++)
    {
        sem_init(&chopsticks[i], 0, 1);
    }

    for (int i = 0; i < N; i++)
    {
        pthread_create(&philo[i], NULL, philosopher, &philosophers[i]);
    }

    for (int i = 0; i < N; i++)
    {
        pthread_join(philo[i], NULL);
    }

    for (int i = 0; i < N; i++)
    {
        sem_destroy(&chopsticks[i]);
    }

    return 0;
}
