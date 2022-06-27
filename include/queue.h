#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <math.h>
#include <stdbool.h>


typedef float queue_value_t;
#define NO_VALUE (queue_value_t)INFINITY

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

bool IsEmpty(myqueue_t *queue);

bool IsFull(myqueue_t *queue);

void Push(myqueue_t *queue, queue_value_t value);

queue_value_t Pop(myqueue_t *queue);

queue_value_t Front(myqueue_t *queue);

queue_value_t Back(myqueue_t *queue);

void PrintQueue(myqueue_t *queue);

void Queue();

#endif //QUEUE_H
