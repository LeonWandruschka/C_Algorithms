#include <stdio.h>
#include <stdlib.h>

#include "queue.h"


myqueue_t *CreateQueue(uint32_t capacity)
{
    myqueue_t *queue = (myqueue_t *)malloc(sizeof(myqueue_t));

    if (queue == NULL)
        return NULL;

    size_t data_size = capacity * sizeof(queue_value_t);
    queue_value_t *data = (queue_value_t *)malloc(data_size);

    if (data == NULL)
    {
        free(queue);
        return NULL;
    }

    queue->front_id = 0u;
    queue->back_id = 0u;
    queue->capacity = capacity;
    queue->size = 0u;
    queue->data = data;

    return queue;
}


myqueue_t *FreeQueue(myqueue_t *queue)
{
    if (queue != NULL)
    {
        if (queue->data != NULL)
        {
            free(queue->data);
        }
        free(queue);
    }
    return NULL;
}


bool QueueIsEmpty(myqueue_t *queue)
{
    return (queue->size == 0u);
}


bool QueueIsFull(myqueue_t *queue)
{
    return (queue->size == queue->capacity);
}


void PushQueue(myqueue_t *queue, queue_value_t value)
{
    if (QueueIsFull(queue))
    {
        return;
    }
    
        
    queue->data[queue->size] = value;
    queue->size++;
}


queue_value_t PopQueue(myqueue_t *queue)
{
    if (QueueIsEmpty(queue))
        return NO_VALUE;
    queue->size--;
    return queue->data[queue->size];
}


queue_value_t FrontQueue(myqueue_t *queue)
{
    if (QueueIsEmpty(queue))
        return NO_VALUE;
    return queue->data[queue->front_id];
}


queue_value_t BackQueue(myqueue_t *queue)
{
    if (QueueIsEmpty(queue))
        return NO_VALUE;
    return queue->data[queue->back_id];
}


void PrintQueue(myqueue_t *queue)
{
    if (queue == NULL)
        return;

    printf(
        "The stack contains %u elements with a capacity of %u.\n",
        queue->size,
        queue->capacity
    );
    
    for (int32_t i = 0; i < queue->size; i++)
    {
        printf("Index: %d, Value %f\n", i, queue->data[i]);
    }
}

/*<-- SIMPLE CALL TO NOT CLUTTER THE MAIN.C -->*/
void Queue()
{
    uint32_t capacity = 4u;
    myqueue_t *queue = CreateQueue(capacity);
    PushQueue(queue, 2.0f);
    PushQueue(queue, 3.0f);
    PrintQueue(queue);
    queue = FreeQueue(queue);
}
