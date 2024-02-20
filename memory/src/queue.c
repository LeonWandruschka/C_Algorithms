#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

/**
 * @brief Create a Queue object
 * 
 * @param capacity 
 * @return myqueue_t* 
 */
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
    queue->back_id = capacity-1;
    queue->capacity = capacity;
    queue->size = 0u;
    queue->data = data;

    return queue;
}

/**
 * @brief Delete Queue object
 * 
 * @param queue 
 * @return myqueue_t* 
 */
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

/**
 * @brief Check if Queue is empty
 * 
 * @param queue 
 * @return true 
 * @return false 
 */
bool QueueIsEmpty(myqueue_t *queue)
{
    return (queue->size == 0u);
}

/**
 * @brief Check if Queue is full
 * 
 * @param queue 
 * @return true 
 * @return false 
 */
bool QueueIsFull(myqueue_t *queue)
{
    return (queue->size == queue->capacity);
}

/**
 * @brief Put new data in the Queue object
 * 
 * @param queue 
 * @param value 
 */
void PushQueue(myqueue_t *queue, queue_value_t value)
{
    if (QueueIsFull(queue))
        return;
        
    queue->back_id = (queue->back_id + 1u) % queue->capacity;
    queue->data[queue->back_id] = value;
    queue->size++;
}

/**
 * @brief Delete data from Queue object
 * 
 * @param queue 
 * @return queue_value_t 
 */
queue_value_t PopQueue(myqueue_t *queue)
{
    if (QueueIsEmpty(queue))
        return QUEUE_NO_VALUE;
    
    queue_value_t value = queue->data[queue->front_id];
    queue->front_id = (queue->front_id + 1u) % queue->capacity;
    queue->size--;
    return value;
}

/**
 * @brief First value of the Queue
 * 
 * @param queue 
 * @return queue_value_t 
 */
queue_value_t FrontQueue(myqueue_t *queue)
{
    if (QueueIsEmpty(queue))
        return QUEUE_NO_VALUE;
    return queue->data[queue->front_id];
}

/**
 * @brief Last element of the Queue
 * 
 * @param queue 
 * @return queue_value_t 
 */
queue_value_t BackQueue(myqueue_t *queue)
{
    if (QueueIsEmpty(queue))
        return QUEUE_NO_VALUE;
    return queue->data[queue->back_id];
}

/**
 * @brief Print the whole queue
 * 
 * @param queue 
 */
void PrintQueue(myqueue_t *queue)
{
    if (queue == NULL)
        return;

    printf(
        "The queue contains %u elements with a capacity of %u.\n",
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
