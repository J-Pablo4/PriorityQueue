#include <stdio.h>

#include "PriorityQueue.h"
int main() {
    PriorityQueue *pq = p_queue_new();

    p_queue_enqueue(pq, "Mundo", 5);
    p_queue_enqueue(pq, "Hola", 4);
    p_queue_enqueue(pq, "Espero que esto", 3);
    p_queue_enqueue(pq, "Funcione!", 2);
    p_queue_enqueue(pq, "\nIt", 1);
    p_queue_enqueue(pq, "Works!", 0);
    

    while (!p_queue_empty(pq))
    {
        char* message = p_queue_dequeue(pq);
        printf("%s ", message);
    }


    return 0;
}
