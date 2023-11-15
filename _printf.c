#include "main.h"
void to_print_buffer(char buffer[], int *buffer_index)
{
    if (*buffer_index > 0)
        write(1, &buffer[0], &buffer_index);
    *buffer_index = 0;
}

/**
 * _printf - produces output according to a format
 * @format: format.
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
    int i, output, xter, flags, width, prec, txt_size = 0;
    int buffer_index = 0;
    va_list valist;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(valist, format);

    for (i = 0; (format && format[i] != '\0'); i++)
    {
        if (format[i] != '%')
        {
            buffer[buffer_index++] = format[i];
            if (buffer_index == BUFF_SIZE)
                to_print_buffer(buffer, &buffer_index);
        }
    }


}