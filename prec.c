#include "main.h"

/**
 * print_precision - calculates precision
 * @formatted_string: to print the args
 * @print_args: list of arguments to be printed
 * @arg_list: receive a param
 * Return: precision
*/
int print_precision(const char *formatted_string, int *print_args, va_list arg_list)
{
    int curr_index = *print_args + 1;
    int prec = -1;

    if (formatted_string[curr_index] != '.')
        return (prec);
    prec = 0;

    for (curr_index += 1; formatted_string[curr_index] != '\0'; curr_index++)
    {
        if (is_num(formatted_string[curr_index]))
        {
            prec = prec * 10;
            prec += formatted_string[curr_index] - '0';
        }
        else if (formatted_string[curr_index] == '*')
        {
            curr_index++;
            prec = va_arg(arg_list, int);
            break;
        }
        else
            break;
    }
    *print_args = curr_index - 1;
    return (prec);
}