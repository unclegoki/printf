#include "main.h"
/**
 * printbinary - print binary numbers
 * @formatted_string: string to print arg
 * @arg_list: list of arguments
 * @i: index
 * @arr_buffer: handles print
 * @flags: active flags
 * @width: get width
 * @prec: precision spec
 * @size: size specifier
 * Return: num of chars  
*/
int handles_print(const char *formatted_string, int *i, va_list arg_list, int flags, int width, int prec, int size)
{
    int i, len = 0;
    int printed_char = -1;
    for_mat format_types[] = {
        {'c', printchar}, {'s', print_str}, {'%', print_percentage}, {'i', print_int}, {'d', print_int}, {'b', print_binary}, {'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal}, {'X', print_uppercase_hex}, {'p', pointer_printer}, {'S', print_ascii}, {'r', print_reverse_string}, {'R', print_rot13string}, {'\0', NULL}
    };
    for (i = 0; format_types[i].fmt != '\0')
    {
        if (formatted_string[*i] == '\0')
            return (-1);
        len += write(1, "%%", 1);
        if (formatted_string[*i - 1] == ' ')
            len += write(1, " ", 1);
        else if (width)
        {
            --(*i);
            while (formatted_string[*i] != ' ' && formatted_string[*i] != '%')
                --(*i);
            if (formatted_string[*i] == ' ')
                --(*i);
            return (1);
        }
        len += write(1, &formatted_string[*i], 1);
        return (len);
    }
    return (printed_char);
}