//
// Created by jplop on 09/11/2022.
//

#include "PriorityQueue.h"
#define INITIAL_SIZE 16

typedef struct node
{
    char *content;
    int priority;
}Box;

struct priorityQueue{
    Box *elements;
    int current_count;
    int size;
};

void heapify_up(PriorityQueue *pq, int index);
void heapify_down(PriorityQueue *pq);

PriorityQueue* p_queue_new()
{
    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    pq->current_count = 0;
    pq->size = INITIAL_SIZE;

    pq->elements = calloc(INITIAL_SIZE, sizeof (Box));

    return pq;
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

int is_full(PriorityQueue *pq)
{
    return pq->current_count == pq->size;
}

void grow_array(PriorityQueue *pq)
{
    pq->size += 16;
    pq->elements = realloc(pq->elements, pq->size * sizeof (Box));

}

Box new_box(int priority, void* data)
{
    Box b;
    b.priority = priority;
    b.content = data;

    return b;
}


void p_queue_enqueue(PriorityQueue *pq, void *data, int priority)
{
    if (is_full(pq))
        grow_array(pq);

    int new_element_index = pq->current_count;

    pq->elements[new_element_index] = new_box(priority, data);

    heapify_up(pq, new_element_index);
    pq->current_count++;
}

void* p_queue_dequeue(PriorityQueue* pq)
{
    void *value_to_return = pq->elements[0]->content;
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

    while(pq->elements[parent].priority > pq->elements[index].priority)
    {
        Box pivot = pq->elements[parent];
        pq->elements[parent] = pq->elements[index];
        pq->elements[index] = pivot;

        index = parent;
        parent = (index-1)/2;
    }
}

void heapify_down(PriorityQueue *pq)
{
    int index = 0;
    int left = (index*2) + 1;
    int right;

    int smaller;

    while (pq->elements[left] !=NULL)
    {
        smaller = left;
        right = (index*2) + 2;
        if(pq->elements[right] != NULL && pq->elements[right]->priority < pq->elements[left]->priority)
        {
            smaller = right;
        }
        if(pq->elements[index]->priority > pq->elements[smaller]->priority)
        {
            Node *pivot = pq->elements[index];
            pq->elements[index] = pq->elements[smaller];
            pq->elements[smaller] = pivot;

            index = smaller;
            left = (index*2) + 1;
        } else
            break;
    }
}