#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*<-- TYPEDEF -->*/

typedef struct _Node_ Node;
typedef struct _List_ List;

/*<-- STRUCTS -->*/

struct _Node_
{
  Node *previous_;
  Node *next_;
  int data_;
};

struct _List_
{
  Node *first_;
  Node *last_;
  int size_;
};

/*<-- FUNCTIONS -->*/

Node *createNode(void);
bool freeNode(Node *node);
List *createList(void);
bool freeList(List *list);
Node *appendNodeToEndOfList(List *list, Node *node, bool check_for_existing_node);
List *appendListToEndOfList(List *list, List *list_to_append);
bool removeNodeFromList(List *list, Node *node);
Node *removeNodeWithValue(List* list, int data);
Node *remove_first(List *list);
bool checkElementInList(Node *current_node, Node *node_to_check);
void printList(List *list);

#endif //DOUBLY_LINKED_LIST_H