//
// Created by jplop on 09/11/2022.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct priorityQueue PriorityQueue;

PriorityQueue* p_queue_new();
void p_queue_enqueue(PriorityQueue* pq, char *element, int priority);

int p_queue_empty(PriorityQueue* pq);

void* p_queue_dequeue(PriorityQueue* pq);

#endif //PRIORITYQUEUE_PRIORITYQUEUE_H
