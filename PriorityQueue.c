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

Node* node_new(char *element, int priority)
{
    Node *new_node = malloc(sizeof (Node));
    new_node->priority = priority;
    new_node->element = element;

    return new_node;
}

PriorityQueue* p_queue_new()
{
    PriorityQueue *new_queue = malloc(sizeof(PriorityQueue));
    new_queue->current_count = 0;
    new_queue->size = INITIAL_SIZE;

    new_queue->elements = calloc(INITIAL_SIZE, sizeof (Node));

    return new_queue;
}

int p_queue_empty(PriorityQueue* pq)
{
    for(int i = 0; i < pq->size; i++)
    {
        if(pq->elements[i] == NULL)
            continue;
        else
            return 0;
    }
    return 1;
}

void p_queue_enqueue(PriorityQueue* pq, char *element, int priority)
{
    if(p_queue_empty(pq))
    {
        pq->elements[0] = node_new(element, priority);
    } else
    {
        if(pq->current_count < pq->size)
        {

        }
    }
}