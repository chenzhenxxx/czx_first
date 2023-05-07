#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];

void* philosopher(void* num) {
  int id = *(int*)num;

  int right_fork = (id + 1) % NUM_PHILOSOPHERS;
  int left_fork = id;

  while (1) {
    // 模拟思考
    sleep(rand() % 10);

    // 放下右手边的叉子
    pthread_mutex_lock(&forks[right_fork]);

    // 等待左手边的叉子
    pthread_mutex_lock(&forks[left_fork]);

    // 吃意大利面
    printf("Philosopher %d is eating.\n", id);

    // 放下左手边的叉子
    pthread_mutex_unlock(&forks[left_fork]);

    // 放下右手边的叉子
    pthread_mutex_unlock(&forks[right_fork]);
  }
}

int main(int argc, char** argv) {
  int i;
  for (i = 0; i < NUM_PHILOSOPHERS; i++) {
    pthread_mutex_init(&forks[i], NULL);
  }

  for (i = 0; i < NUM_PHILOSOPHERS; i++) {
    int* num = malloc(sizeof(*num));
    *num = i;
    pthread_create(&philosophers[i], NULL, philosopher, num);
  }

  for (i = 0; i < NUM_PHILOSOPHERS; i++) {
    pthread_join(philosophers[i], NULL);
  }

  return 0;
}
