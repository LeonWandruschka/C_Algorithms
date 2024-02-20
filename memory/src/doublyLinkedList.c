
#include "doublyLinkedList.h"

/// @brief Allocates memory for a new node and initalizes it
/// @return Returns address of the created node
Node *createNode(void)
{
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL)
  {
    return NULL;
  }

  // Initialize node
  node->next_ = NULL;
  node->previous_ = NULL;
  node->data_ = 0;

  return node;
}

/// @brief Frees the memory of a node
/// @param node Address to a _Node_ struct
/// @return true if the node has been freed / false if node was NULL
bool freeNode(Node *node)
{
  if (node == NULL)
  {
    return false;
  }

  free(node);
  return true;
}

/// @brief Allocates memory for a new list and initalizes it
/// @return Returns address of the created list
List *createList(void)
{
  List *list = (List *)malloc(sizeof(List));
  if (list == NULL)
  {
    return NULL;
  }

  list->size_ = 0;
  list->first_ = NULL;
  list->last_ = NULL;

  return list;
}

/// @brief Frees the memory of a list and all nodes in it
/// @param list Address to a _List_ struct
/// @return true if the list and all nodes has been freed / false if list was NULL
bool freeList(List *list)
{
  if (list == NULL)
  {
    return false;
  }

  int list_size = list->size_;
  if (list_size > 0)
  {
    Node *current_node;
    for (int i = 0; i < list_size; i++)
    {
      current_node = list->last_;
      if (!removeNodeFromList(list, current_node))
      {
        return false;
      }
      if (!freeNode(current_node))
      {
        return false;
      }
    }
  }

  free(list);
  return true;
}

/// @brief Checks if the adress of a node is already in a list (rekursive)
/// @param current_node Address of the node to begin the check
/// @param node_to_check The address of the node to check
/// @return Returns true if the element is already in the list.
bool checkElementInList(Node *current_node, Node *node_to_check)
{
  // Check if list is empty
  if (current_node == NULL)
  {
    return false;
  }
  // Check if the current node is the same as the one to check
  if (current_node == node_to_check)
  {
    return true;
  }
  // Else go recursive into the function with the next element in the list
  else
  {
    return checkElementInList(current_node->next_, node_to_check);
  }
  return false;
}

/// @brief Append a node to the end of a list
/// @param list Address of the list to append to
/// @param node Address of the node
/// @param check_for_existing_node true: same node can only be saved once
/// | false: the same node can be saved multiple times
/// @return Returns the address of the appendend node
Node *appendNodeToEndOfList(List *list, Node *node, bool check_for_existing_node)
{
  // Element is already in the list
  if ((check_for_existing_node ? checkElementInList(list->first_, node) : false))
  {
    return node;
  }

  if (list->size_ == 0)
  {
    list->first_ = node;
    list->last_ = node;
    list->size_++;
  }
  else
  {
    list->last_->next_ = node;     // Set next from last element in list to the new node
    node->previous_ = list->last_; // Set pointer to now second last element
    list->last_ = node;
    list->size_++;
  }
  return node;
}

List *appendListToEndOfList(List *list, List *list_to_append)
{
  if (list->size_ == 0)
  {
    list->first_ = list_to_append->first_;
    list->last_ = list_to_append->last_;
    list->size_ = list_to_append->size_;
  }
  else
  {
    list->last_->next_ = list_to_append->first_;     // Set next from last element in list to the new node
    list_to_append->first_->previous_ = list->last_;
    list->last_ = list_to_append->last_;
    list->size_ = list->size_ + list_to_append->size_;
  }
  list_to_append->first_ = NULL;
  list_to_append->last_ = NULL;
  list_to_append->size_ = 0;
  return list;
}

/// @brief Removes a node from the list
/// @param list Address of the list
/// @param node Address of node which should be removed
/// @return true: could be removed | false: could not be removed
bool removeNodeFromList(List *list, Node *node)
{
  if (list->size_ == 0)
  {
    return NULL;
  }

  if (node->next_ == NULL && node->previous_ == NULL)
  {
    list->first_ = NULL;
    list->last_ = NULL;
    list->size_--;

    return true;
  }
  else if (node->next_ == NULL) // Node is the last element in the list
  {
    list->last_ = node->previous_; // Set last list element to the one before this node
    node->previous_->next_ = NULL; // Set the pointer from the second last node to this to NULL
    list->size_--;

    return true;
  }
  else if (node->previous_ == NULL) // Node is first element in list
  {
    list->first_ = node->next_;    // Set first list element to the one after this node
    node->next_->previous_ = NULL; // Set the pointer from the second node to this to NULL
    list->size_--;

    return true;
  }
  else
  {
    node->next_->previous_ = node->previous_;
    node->previous_->next_ = node->next_;
    list->size_--;

    return true;
  }
  return false;
}

/// @brief Remove a node from a list with a specific value of playing_card_
/// @param list List where the node should be removed
/// @param value Value of playing_card_ that should be removed
/// @return Returns the address of the node that is removed from the list
Node *removeNodeWithValue(List *list, int data)
{
  Node *current_node = list->first_;
  while (current_node != NULL)
  {
    if (current_node->data_ == data)
    {
      if (current_node == list->first_)
      {
        list->first_ = current_node->next_;
      }
      else
      {
        current_node->previous_->next_ = current_node->next_;
      }
      if (current_node == list->last_)
      {
        list->last_ = current_node->previous_;
      }
      else
      {
        current_node->next_->previous_ = current_node->previous_;
      }
      if(list->first_ != NULL)
      {
        list->first_->previous_ = NULL;
      }
      if(list->last_ != NULL)
      {
        list->last_->next_ = NULL;
      }
      
      list->size_--;
      current_node->previous_ = NULL;
      current_node->next_ = NULL;
      return current_node;
    }
    current_node = current_node->next_;
  }
  return NULL; // value not found
}

/// @brief Remove first node in list
/// @param list 
/// @return 
Node *remove_first(List *list)
{
  if (list->size_ == 0)
  {
    return NULL;
  }

  Node *removed = list->first_;
  Node *second = list->first_->next_;
  list->first_ = second;
  list->size_--;
  return removed;
}

/// @brief Print the whole List without trailing \n
/// @param list List to be printed
void printList(List *list)
{
  Node *current_node = list->first_;
  int count = 0;
  while (current_node != NULL)
  {
    // Example print if data is an integer
    printf("List element %d, value: %d\n", count, current_node->data_);
    current_node = current_node->next_;
    count ++;
  }
}