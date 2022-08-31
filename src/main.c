#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "recursiveFib.h"
#include "dynamicFib.h"
#include "patternSearch.h"
#include "stack.h"
#include "queue.h"
#include "linkedList.h"
#include "thread.h"

void FunctionCall();


/**
 * @brief This is the main function remove the // befor the function you want to test.
 */
int main(void) // int argc, char const *argv[]
{
    //FunctionCall();  
    //ThreadCall();
    LINKEDLIST();
    return 0;
}
 

/**
 * @brief Easy access to all functions of the repository
 */
void FunctionCall()
{
    while(1)
    {
        char func;
        printf("Which function du you want to test? ");
        scanf("%c", &func);

        switch (func)
        {
        case 'a':
            //Works fine for smaller numbers -> Really slow with higher numbers >= 40
            RecursiveFib(10);
            exit(0);
            break;

        case 'b':
            //Really fast also works with higher numbers
            DynamicFib(60);
            exit(0);
            break;

        case 'c':
            //Search for a specific pattern in a Text
            PatternSearch();
            exit(0);
            break;

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
            //Double Linked List
            LINKEDLIST();
            exit(0);
            break;

        case 'X':
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
            break;
        }
    }
}




