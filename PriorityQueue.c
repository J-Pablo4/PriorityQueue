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

void heapify_up(PriorityQueue *pq, int index);
void heapify_down(PriorityQueue *pq);

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

void p_queue_enqueue(PriorityQueue *pq, void *data, int priority)
{
    if(p_queue_empty(pq))
    {
        pq->elements[0] = node_new(data, priority);
        pq->current_count++;
    } else
    {
//        Children left: 2n + 1
//        Children right: 2n + 2
//        Parent: (n-1)/2
        if(pq->current_count < pq->size)
        {
            for (int i = 0; i < pq->size; ++i)
            {
                if(pq->elements[i] == NULL)
                {
                    pq->elements[i] = node_new(data, priority);
                    pq->current_count++;

                    heapify_up(pq, i);
                    return;
                }
            }
        }
    }
}

void* p_queue_dequeue(PriorityQueue* pq)
{
    void *value_to_return = pq->elements[0]->element;
    Node *to_free = pq->elements[0];

    pq->elements[0] = pq->elements[pq->current_count-1];

    pq->elements[pq->current_count-1] = NULL;

    free(to_free);
    pq->current_count--;

    heapify_down(pq);
    return value_to_return;
}

void heapify_up(PriorityQueue *pq, int index)
{
    int parent = (index-1)/2;

    while(pq->elements[parent]->priority > pq->elements[index]->priority)
    {
        Node *pivot = pq->elements[parent];
        pq->elements[parent] = pq->elements[index];
        pq->elements[index] = pivot;

        index = parent;
        parent = (index-1)/2;

        if(index == 0)
            break;
    }
}

void heapify_down(PriorityQueue *pq)
{
    int index = 0;
    int left = (index*2) + 1;
    int right = (index*2) + 2;

    while (pq->elements[left] !=NULL)
    {
        if(pq->elements[index]->priority > pq->elements[left]->priority)
        {
            Node *pivot = pq->elements[index];
            pq->elements[index] = pq->elements[left];
            pq->elements[left] = pivot;

            index = left;
            left = (index*2) + 1;
            right = (index*2) + 2;

        } else if(pq->elements[right] != NULL)
        {
            if(pq->elements[index]->priority > pq->elements[right]->priority )
            {
                Node *pivot = pq->elements[index];
                pq->elements[index] = pq->elements[right];
                pq->elements[right] = pivot;

                index = right;
                left = (index*2) + 1;
                right = (index*2) + 2;

                if(pq->elements[left] !=NULL || pq->elements[right] !=NULL)
                {
                    index = 0;
                    left = (index*2) + 1;
                    right = (index*2) + 2;
                }
            }
        } else
            break;
    }
}