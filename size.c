#include "main.h"

/**
 * print_size = prints the size to cast arg
 * @formatted_string: to print the args
 * @arg_list: receive a param
 * Return: precision
*/
int print_size(const char *formatted_string, int *arg_list)
{
    int curr_index = *arg_list + 1;
    int size = 0;

    if (formatted_string[curr_index] == 'l')
        size = LONG_SIZE;
    else if (formatted_string[curr_index] == 'h')
        size = SHORT_SIZE;

    if (size == 0)
        *arg_list = curr_index - 1;
    else
        *arg_list = curr_index;

    return (size);
}