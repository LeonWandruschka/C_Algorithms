#include <stdio.h>
#include <stdlib.h>

#include "stack.h"



/**
 * @brief Create a Stack object
 * 
 * @param capacity 
 * @return stack_t* 
 */
mystack_t *CreateStack(uint32_t capacity)
{
    mystack_t *stack = (mystack_t *)malloc(sizeof(mystack_t));

    if (stack == NULL)
        return NULL;

    size_t data_size = capacity * sizeof(stack_value_t);
    stack_value_t *data = (stack_value_t *)malloc(data_size);

    if (data == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0u;
    stack->data = data;

    return stack;
}

/**
 * @brief Free the memory of a given Stack object
 * 
 * @param stack 
 * @return stack_t* 
 */
mystack_t *FreeStack(mystack_t *stack)
{
    if (stack != NULL)
    {
        if (stack->data != NULL)
        {
            free(stack->data);
        }
        free(stack);
    }
    return NULL;
}

/**
 * @brief Check if the Stack object is empty
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool StackIsEmpty(mystack_t *stack)
{
    return (stack->size == 0u);
}

/**
 * @brief Check if the Stack object is full
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool StackIsFull(mystack_t *stack)
{
    return (stack->size == stack->capacity);
}

/**
 * @brief Push a new object to the stack
 * 
 * @param stack 
 */
void PushStack(mystack_t *stack, stack_value_t value)
{
    if (StackIsFull(stack))
    {
        return;
    }
        
    stack->data[stack->size] = value;
    stack->size++;
}

/**
 * @brief Pop the object on top of the stack
 * 
 * @param stack 
 * @return stack_value_t 
 */
stack_value_t PopStack(mystack_t *stack)
{
    if (StackIsEmpty(stack))
        return STACK_NO_VALUE;
    stack->size--;
    return stack->data[stack->size];
}


/**
 * @brief Return the top object of the stack
 * 
 * @param stack 
 * @return stack_value_t 
 */
stack_value_t TopStack(mystack_t *stack)
{
    if (StackIsEmpty(stack))
        return STACK_NO_VALUE;
    return stack->data[stack->size - 1];
}

/**
 * @brief Print the whole stack
 * 
 * @param stack 
 */
void PrintStack(mystack_t *stack)
{
    if (stack == NULL)
        return;

    printf(
        "The stack contains %u elements with a capacity of %u.\n",
        stack->size,
        stack->capacity
    );
    
    for (uint32_t i = 0; i < stack->size; i++)
    {
        printf("Index: %d, Value %f\n", i, stack->data[i]);
    }
}


/*<-- SIMPLE CALL TO NOT CLUTTER THE MAIN.C -->*/
void Stack()
{
    uint32_t capacity = 4u;
    mystack_t *stack = CreateStack(capacity);
    PushStack(stack, 2.0f);
    PushStack(stack, 3.0f);
    PrintStack(stack);
    stack = FreeStack(stack);
}
