#include <stdio.h>

#include "PriorityQueue.h"
int main() {
    PriorityQueue *pq = p_queue_new();

    p_queue_enqueue(pq, "Mundo", 3);
    p_queue_enqueue(pq, "Hola", 2);
    p_queue_enqueue(pq, "Espero que esto", 0);
    p_queue_enqueue(pq, "Funcione!", 13);
    p_queue_enqueue(pq, "\nIt", 12);
    p_queue_enqueue(pq, "works!", 0);
    

    while (!p_queue_empty(pq))
    {
        char* message = p_queue_dequeue(pq);
        printf("%s\n", message);
    }


    return 0;
}
