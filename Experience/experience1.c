/*********************************************
 @Author       : Mr.Wang
 @Date         : 2021-04-12 16:38:45
 @FilePath     : /test2.c
 @Description  : message
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

int philosophers[N] = {1, 2, 3, 4, 5};

void *philosopher(void *arg)
{
    int i = *(int *)arg;
    int left = i;
    int right;
    if (i != N)
    {
        right = i + 1;
    }
    else
    {
        right = 1;
    }
    while (1)
    {
        if (i % 2 == 0)
        {
            printf("Philosopher %d is thinking.\n", i);
            sleep(3);

            sem_wait(&chopsticks[right]);
            printf("Philosopher %d fetches chopstick %d\n", i, right);
            sem_wait(&chopsticks[left]);
            printf("Philosopher %d fetches chopstick %d\n", i, left);
            printf("Philosopher %c is eating.\n", i);
            sleep(3);
            sem_post(&chopsticks[left]);
            printf("Philosopher %d release chopstick %d\n", i, left);
            sem_post(&chopsticks[right]);
            printf("Philosopher %d release chopstick %d\n", i, right);
        }

        else
        {
            printf("Philosopher %d is thinking.\n", i);
            sleep(3);

            sem_wait(&chopsticks[left]);
            printf("Philosopher %d fetches chopstick %d\n", i, left);
            sem_wait(&chopsticks[right]);
            printf("Philosopher %d fetches chopstick %d\n", i, right);
            printf("Philosopher %d is eating.\n", i);
            sleep(3);
            sem_post(&chopsticks[left]);
            printf("Philosopher %d release chopstick %d\n", i, left);
            sem_post(&chopsticks[right]);
            printf("Philosopher %c release chopstick %d\n", i, right);
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
