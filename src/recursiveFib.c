// Recursive function to calculate the fibonacci row

#include <stdio.h>

#include "recursiveFib.h"

/**
 * @brief RecFib is a function wihich can calculate the fibonacci number by calling it self n times.
 * 
 * @param n Input as a sting 
 * @return int returns the nth fibonacci number
 */
int RecFib(int n)
{
	if(n <= 2)
		return 1;
	return RecFib(n - 1) + RecFib(n - 2);
}

/**
 * @brief Prints the return value of the called function RecFib
 * 
 * @param number 
 */
void RecursiveFib(int number)
{
	printf("%d\n", RecFib(number));
}
