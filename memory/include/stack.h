#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <math.h>
#include <stdbool.h>


typedef float stack_value_t;
#define STACK_NO_VALUE (stack_value_t)INFINITY

typedef struct stack
{
    uint32_t size;
    uint32_t capacity;
    stack_value_t *data;
} mystack_t;


mystack_t *CreateStack(uint32_t capacity);

mystack_t *FreeStack(mystack_t *stack);

bool StackIsEmpty(mystack_t *stack);

bool StackIsFull(mystack_t *stack);

void PushStack(mystack_t *stack, stack_value_t value);

stack_value_t PopStack(mystack_t *stack);

stack_value_t TopStack(mystack_t *stack);

void PrintStack(mystack_t *stack);

void Stack();

#endif //STACK_H
