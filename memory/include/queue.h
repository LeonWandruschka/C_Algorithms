#ifndef QUEUE_H
#define QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <math.h>
#include <stdbool.h>


typedef float queue_value_t;
#define QUEUE_NO_VALUE (queue_value_t)INFINITY

typedef struct queue
{
    u_int32_t front_id;
    uint32_t back_id;
    uint32_t size;
    uint32_t capacity;
    queue_value_t *data;
} myqueue_t;


myqueue_t *CreateQueue(uint32_t capacity);
myqueue_t *FreeQueue(myqueue_t *queue);
bool QueueIsEmpty(myqueue_t *queue);
bool QueueIsFull(myqueue_t *queue);
void PushQueue(myqueue_t *queue, queue_value_t value);
queue_value_t PopQueue(myqueue_t *queue);
queue_value_t FrontQueue(myqueue_t *queue);
queue_value_t BackQueue(myqueue_t *queue);
void PrintQueue(myqueue_t *queue);
void Queue();

#ifdef __cplusplus
}
#endif

#endif //QUEUE_H
