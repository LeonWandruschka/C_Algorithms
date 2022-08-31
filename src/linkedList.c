#include <stdlib.h>

#include "linkedList.h"



node_t * CreateNode(dll_datatype_t value)
{
    node_t * node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL)
        return NULL;
    
    dll_datatype_t * node_value = (dll_datatype_t *)malloc(sizeof(dll_datatype_t));
    if (node_value == NULL)
    {
        free(node);
        return NULL;
    }

    *node_value = value;


    node->next = NULL;
    node->previous = NULL;
    node->value = node_value;
    return node;
}

node_t * FreeNode(node_t *node)
{
    if (node == NULL)
        return NULL;
    
    free(node->value);
    free(node);

    return NULL;
}

list_t * CreateList(void)
{
    list_t * list = (list_t *)malloc(sizeof(list_t));
    if (list == NULL)
        return NULL;

    list->back = NULL;
    list->front = NULL;
    list->size = 0;

    return list;
}

list_t * FreeList(list_t *list)
{
    if (list == NULL)
        return NULL;

    free(list);
    return NULL;
}

void * AddNode()
{
    return NULL;
}

void * RemoveNode()
{
    return NULL;
}


void LINKEDLIST(void)
{
    list_t *ll = CreateList();
    node_t *a = CreateNode(1);
    node_t *b = CreateNode(2);
    node_t *c = CreateNode(3);
    ll = FreeList(ll);
}
