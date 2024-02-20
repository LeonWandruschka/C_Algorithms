
#include <stdio.h>
#include <stdlib.h>

#include "recursiveFib.h"
#include "dynamicFib.h"
#include "patternSearch.h"
#include "stack.h"
#include "queue.h"
#include "doublyLinkedList.h"


void FunctionCall();


/**
 * @brief This is the main function remove the // befor the function you want to test.
 */
int main(void) // int argc, char const *argv[]
{
  FunctionCall();  

  return 0;
}


/**
 * @brief Easy access to all functions of the repository
 * 
 */
void FunctionCall()
{
  while(1)
  {
    char func;
    printf("Which function du you want to test? ");
    func = getc(stdin);

    switch (func)
    {
    case 'a': 
      {
        // Works fine for smaller numbers -> 
        // Really slow with higher numbers >= 40
        int num = 10;
        printf("\nRunning recursive fibonacci function with value of %d...\n", num);
        printf("RecursiveFib(%d) = ", num);
        RecursiveFib(num);
        printf("\n");
        //exit(0);
        break;
      }
    case 'b':
      {
        //Really fast also works with higher numbers
        int num = 60;
        printf("\nRunning dynamic fibonacci function with value of %d...\n", num);
        printf("RecursiveFib(%d) = ", num);
        DynamicFib(num);
        printf("\n");
        break;
      }
    case 'c':
      {
        //Search for a specific pattern in a Text
        char text[] = "THIS IS A TEXT TO SEARCH A PATTERN";
        char pattern[] = "IS A";

        printf("\nRunning pattern search...\n");

        uint32_t x = PatternSearch(text, pattern);
        if (x == -1)
        {
            printf("No matched pattern found!\n");
        }
        printf("Pattern found at position %d\n", x);

        printf("\n");
        break;
      }
    case 'd':
        //Creating your own Stack to Push and pop your data
        Stack();
        exit(0);
        break;
    case 'e':
        //Creating your own Queue to Push and pop your data
        Queue();
        exit(0);
        break;
    case 'f':
      {
        printf("\nRunning double linked list...\n");

        List *list = createList(); ///< Creates a new list
        Node *node = createNode(); ///< Createa node
        
        node->data_ = 10;
        appendNodeToEndOfList(list, node, false);

        node = createNode();        ///< Create another node
        node->data_ = 20;
        appendNodeToEndOfList(list, node, false);

        node = createNode();        ///< Create another node
        node->data_ = 120;
        appendNodeToEndOfList(list, node, false);

        printList(list);

        freeList(list);

        printf("\n");

        break;
      }

    case 'X':
    case 'x':
        //Exitiong the programm
        exit(0);

    default:
        printf("Enter the following characters to call the specific functions:\n");
        printf("(a): Recursive Fibonacci\n");
        printf("(b): Dynamic Fibonacci\n");
        printf("(c): Patternsearch\n");
        printf("(d): Stack\n");
        printf("(e): Queue\n");
        printf("(X): Exit the programm\n");
        fflush(stdin);
        break;
    }
  fflush(stdin);
  }
}




