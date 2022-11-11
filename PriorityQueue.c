//
// Created by jplop on 09/11/2022.
//

#include "PriorityQueue.h"
#define INITIAL_SIZE 16

typedef struct node
{
    char *element;
    int priority;
}Node;

struct priorityQueue{
    Node **elements;
    int current_count;
    int size;
};

PriorityQueue* p_queue_new()
{
    PriorityQueue *new_queue = malloc(sizeof(PriorityQueue));
    new_queue->current_count = 0;
    new_queue->size = INITIAL_SIZE;

    new_queue->elements = calloc(INITIAL_SIZE, sizeof (Node));

    return new_queue;
}

void p_queue_enqueue(PriorityQueue* pq, void *element, int priority)
{

}