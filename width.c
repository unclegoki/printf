#include "main.h"

/**
 * print_width - prints the width
 * @formatted_string: to print the args
 * @print_args: list of arguments to be printed
 * @arg_list: receive a param
 * Return: precision
*/
int print_width(const char *formatted_string, int *print_args, va_list arg_list)
{
    int curr_index;
    int width = 0;

    for (curr_index = *print_args + 1; formatted_string[curr_index] != '\0'; curr_index++)
    {
        if (is_number(formatted_string[curr_index]))
        {
            width *= 10;
            width += formatted_string[curr_index] - '0';
        }
        else if (formatted_string[curr_index] == '*')
        {
            curr_index++;
            width = va_arg(arg_list, int);
            break;
        }
        else
            break;
    }
    *print_args = curr_index - 1;

    return (width);
}