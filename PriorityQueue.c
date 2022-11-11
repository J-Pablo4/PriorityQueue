//
// Created by jplop on 09/11/2022.
//

#include "PriorityQueue.h"
#define INITIAL_SIZE 16

typedef struct node{
    int priority;
    void *value;
}Node;

struct priorityQueue{
    Node* arry;
    int si
};

Node* node_new(void *element, int priority)
{
    Node *new_node = malloc(sizeof (Node));
    new_node->value = element;
    new_node->priority = priority;
    return new_node;
}

PriorityQueue* p_queue_new()
{
    PriorityQueue *new_queue = malloc(sizeof(PriorityQueue));
    new_queue->arry = calloc(16, sizeof (Node));

    return new_queue;
}

void p_queue_enqueue(PriorityQueue* pq, void *element, int priority)
{
    
}