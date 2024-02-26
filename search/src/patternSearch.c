#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "patternSearch.h"

/**
 * @brief PatSearch is a Function to search for specific patterns in a text. 
 * (Be aware that its case sensitive!)
 *
 * @param text Input as a char array / as a string
 * @param pattern Input as a char array / as a string
 * @return int returns the position of the match or -1 if no match was found
 */
uint32_t PatternSearch(char *text, char *pattern)
{
    uint32_t t = strlen(text);
    uint32_t p = strlen(pattern);

    for (uint32_t i = 0; i < t - p; i++)
    {
        uint32_t j;
        for (j = 0; j < p; j++)
            if (text[i + j] != pattern[j])
                break;

        if (j == p)
            return i + 1;
    }
    return -1;
}
