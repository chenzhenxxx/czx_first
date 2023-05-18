//calc.h
#ifndef CALC_H
#define calc_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void *producer();
void *consumer();
void sem_mutex_dead();
void sem_mutex_init();


#endif

