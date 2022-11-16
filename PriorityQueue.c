//
// Created by jplop on 09/11/2022.
//

#include "PriorityQueue.h"
#define INITIAL_SIZE 2

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
    return pq->current_count == 0;
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

void heapify_down(PriorityQueue *pq)
{
    pq->elements[0] = pq->elements[pq->current_count];

    int index = 0;
    int left;
    int right;

    while (index < pq->current_count)
    {
        left = (index*2) + 1;
        right = (index*2) + 2;

        if (right < pq->current_count && pq->elements[right].priority < pq->elements[index].priority)
        {
            if (pq->elements[right].priority < pq->elements[left].priority)
            {
                Box pivot = pq->elements[index];
                pq->elements[index] = pq->elements[right];
                pq->elements[right] = pivot;

                index = right;
            } else
            {
                Box pivot = pq->elements[index];
                pq->elements[index] = pq->elements[left];
                pq->elements[left] = pivot;

                index = left;
            }
        } else if(left < pq->current_count && pq->elements[left].priority < pq->elements[index].priority)
        {
            Box pivot = pq->elements[index];
            pq->elements[index] = pq->elements[left];
            pq->elements[left] = pivot;

            index = left;
        } else
            return;
    }
}

void* p_queue_dequeue(PriorityQueue* pq)
{
    if (p_queue_empty(pq))
        exit(EXIT_FAILURE);
    void *to_return = pq->elements[0].content;
    pq->current_count--;

    heapify_down(pq);

    return to_return;
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