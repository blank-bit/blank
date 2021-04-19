/*********************************************
 @Author       : Mr.Wang
 @Date         : 2021-04-12 16:13:38
 @FilePath     : /test1.c
 @Description  : message
*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <pthread.h>
#include <errno.h>
#include <math.h>
#include <unistd.h>

pthread_mutex_t chopstick[6];
void *eat_think(void *arg)
{
    char phi = *(char *)arg;
    int left, right; //左右筷子的编号
    switch (phi)
    {
    case 'A':
        left = 5;
        right = 1;
        break;
    case 'B':
        left = 1;
        right = 2;
        break;
    case 'C':
        left = 2;
        right = 3;
        break;
    case 'D':
        left = 3;
        right = 4;
        break;
    case 'E':
        left = 4;
        right = 5;
        break;
    }

    do
    {
        sleep(3);                             //思考
        pthread_mutex_lock(&chopstick[left]); //拿起左手的筷子
        printf("Philosopher %c fetches chopstick %d\n", phi, left);

        if (pthread_mutex_trylock(&chopstick[right]) == EBUSY)
        {                                           //拿起右手的筷子
            pthread_mutex_unlock(&chopstick[left]); //如果右边筷子被拿走放下左手的筷子
            continue;
        }

        printf("Philosopher %c fetches chopstick %d\n", phi, right);
        printf("Philosopher %c is eating.\n", phi);
        sleep(3);                               //吃饭
        pthread_mutex_unlock(&chopstick[left]); //放下左手的筷子
        printf("Philosopher %c release chopstick %d\n", phi, left);
        pthread_mutex_unlock(&chopstick[right]); //放下左手的筷子
        printf("Philosopher %c release chopstick %d\n", phi, right);
    } while (1);
}

int main()
{
    pthread_t A, B, C, D, E; //5个哲学家

    int i;
    for (i = 0; i < 5; i++)
        pthread_mutex_init(&chopstick[i], NULL);

    pthread_create(&A, NULL, eat_think, "A");
    pthread_create(&B, NULL, eat_think, "B");
    pthread_create(&C, NULL, eat_think, "C");
    pthread_create(&D, NULL, eat_think, "D");
    pthread_create(&E, NULL, eat_think, "E");

    pthread_join(A, NULL);
    pthread_join(B, NULL);
    pthread_join(C, NULL);
    pthread_join(D, NULL);
    pthread_join(E, NULL);

    for (i = 0; i < 5; i++)
        pthread_mutex_destroy(&chopstick[i]);

    return 0;
}
