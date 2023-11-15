#include "main.h"

/**
 * printchar - print char
 * @arg_list: List of args
 * @arr_buffer: buffer array
 * @flags: active flags
 * @width: char witdth
 * @prec: precision spec..
 * @size: specify size
 * Return: num of chars
*/
int printchar(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size)
{
    char c = va_arg(arg_list, int);
    return (handles_write_char_function(c, arr_buffer, flags, width, prec, size));
}

/**
 * print_str - print string
 * @arg_list: list of args
 * @flags: active flags
 * @width: string width
 * @prec: precision specifier
 * @size: specify size
 * Return: num of strings
*/
int print_str(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size)
{
    int len = 0;
    int i;
    char *str = va_arg(arg_list, char *);

    UNUSED(flags);
    UNUSED(size);
    UNUSED(width);
    UNUSED(prec);
    UNUSED(arr_buffer);

    if (str == NULL)
    {
        str = "(null)";
        if (prec > 7)
            str = "      ";
    }
    while (str[len] != '\0')
        len++;
    if (prec >= 0 && prec < len)
        len = prec;
    if (width >len)
    {
        if (flags & FLAG_MINUS)
        {
            write(1, &str[0], len);
            for (i = width - len; i > 0; i--)
                write(1, " ", 1);
            write(1, &str[0], len);
            return (width);
        }
    }
    return (write(1, str, len));
}

/**
 * print_percentage - print % sign
 * @arg_list: arguments list
 * @arr_buffer: handles print
 * @flags: active flags
 * @width: width of output
 * @prec: specified precision
 * @size: size specifier
 * Return: num of char
*/
int print_percentage(va_list arg_list, char arr_buffer[],int flags, int width, int prec, int size)
{
    (void)arg_list;
    (void)flags;
	(void)width;
	(void)prec;
    (void)arr_buffer;
	(void)size;
    /*(void)arg_list;
    (void)flags;*/
    return (_putchar('%'));
}

/**
 * print_integer - print an int
 * @arg_list: arguments list
 * @arr_buffer: handles print
 * @flags: active flags
 * @width: width of output
 * @prec: specified precision
 * @size: size specifier
 * Return: num of char
*/
int print_integer(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size)
{
    int i, is_neg;
    long int n = va_arg(arg_list, long int);
    unsigned long int num;

    n = convert_size_num(n, size);

    if (n == 0)
        arr_buffer[i--] = '0';
    arr_buffer[BUFFER_SIZE - 1] = '\0';
    num = (unsigned long int)n;

    is_neg = 0;
    if (n < 0)
    {
        num = (unsigned long int)((-1 ) * n);
        is_neg = 1;
    }

    i = BUFFER_SIZE - 2;
    while (num > 0)
    {
        arr_buffer[i--] = (num % 10) + '0';
        num /= 10;
    }
    i++;
    return (write_number(is_neg, i, arr_buffer, flags, width, prec, size));
}

/**
 * printbinary - print binary numbers
 * @arg_list: list of arguments
 * @arr_buffer: handles print
 * @flags: active flags
 * @width: get width
 * @prec: precision spec
 * @size: size specifier
 * Return: num of chars  
*/
int printbinary(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size)
{
    // j - n, k = m
    int counter;
    unsigned int i, j, k, sum;
    unsigned int a[32];

    (void)flags;
    (void)size;
    (void)width;
    (void)prec;
    (void)arr_buffer;
    j = va_arg(arg_list, unsigned int);
    k = pow(2, 31);
    a[0] = j / k;
    
    for (i = 1; i < 32; i++)
    {
        k = k/2;
        a[i] = (j / k) % 2;
    } 
    for (i, sum, counter = 0; i < 32; i++)
    {
        sum += a[i];
        if (sum || i == 31)
        {
            char binary_num = '0' + a[i];
            
            write(1, &binary_num, 1);
            counter++;
        }
    }
    return (counter);
}
