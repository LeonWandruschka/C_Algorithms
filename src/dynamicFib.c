#include <stdio.h>

#include "dynamicFib.h"

long DynFib(int n)
{
    long array[n - 1];
    array[0] = 1; // Basevalue for fibonacci 1 = 1
    array[1] = 1; // Basevalue for fibonacci 2 = 1

    // Safe value from the n th fibonacci number in array[n - 1]
    for (long i = 2; i < n; i++)
        array[i] = array[i - 1] + array[i - 2];
    return array[n - 1]; // Return the value
}

void DynamicFib(int number)
{
    printf("%ld\n", DynFib(number));
}
