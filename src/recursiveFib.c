// Recursive function to calculate the fibonacci row

#include <stdio.h>

#include "recursiveFib.h"

int RecFib(int n)
{
	if(n <= 2)
		return 1;
	return RecFib(n - 1) + RecFib(n - 2);
}

void RecursiveFib(int number)
{
	printf("%d\n", RecFib(number));
}
