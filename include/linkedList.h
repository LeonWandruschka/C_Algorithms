#ifndef DOUBLE_LINKEDLIST_H
#define DOUBLE_LINKEDLIST_H

#include <math.h>

typedef float dll_datatype_t;
#define DLL_NOVALUE (dll_datatype_t) INFINITY

typedef struct node
{
    struct node * next;
    struct node * previous;
    dll_datatype_t *value;

} node_t;

typedef struct list  
{
    node_t *front;  //Point to the first node in the list
    node_t *back;   //Point to the last node in the list
    uint32_t size;  //Size of the list
}list_t;

list_t * CreateList(void);
list_t * FreeList(list_t *list);
node_t * CreateNode(dll_datatype_t value);
node_t * FreeNode(node_t *node);

void LINKEDLIST(void);

#endif //DOUBLE_LINKEDLIST_H
