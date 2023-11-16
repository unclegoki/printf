#include "main.h"

/**
 * my_flag - returns needed flags
 * @formatted_string: to print the args
 * @i: receive a param
 * Return: appropriate flag
*/
int my_flag(const char *formatted_string, int *i)
{
    int x, curr;
    int flags = 0;

    const char FLAGS_SYM[]={'-', '+', '0', '#', '\0'};
    const int ARR_FLAGS[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO, FLAG_HASH, FLAG_SPACE, 0};
    for (curr = *i + 1; formatted_string[curr] != '\0'; curr++)
    {
        for (x = 0; FLAGS_SYM[x] != '\0'; x++)
        {
            if (formatted_string[curr] == FLAGS_SYM[x])
            {
		flags |= ARR_FLAGS[x];
                break;
            }
        }
        if (FLAGS_SYM[x] == 0)
            break;
    }
    *i = curr - 1;
    return (flags);
}
