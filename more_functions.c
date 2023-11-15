#include "main.h"

/**
 * print_unsigned - prints unsigned nums
 * @arg_list: List of args
 * @arr_buffer: buffer array to handle print
 * @flags: active flags
 * @width: get width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Num of chars that is printed.
*/
int print_unsigned(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size)
{
    int i = BUFFER_SIZE - 2;
    unsigned long int num = va_arg(arg_list, unsigned long int);
    num = convert_unsigned_int(num, size);

    if (num == 0)
        arr_buffer[i--] = '0';

    arr_buffer[BUFFER_SIZE - 1] = '\0';

    while (num > 0)
    {
        arr_buffer[i--] = (num % 10) + '0';
        num  /= 10;
    }
    i++;

    return (write_unsigned_int(0, i, arr_buffer, flags, width, prec, size));
}

/**
 * print_octa_num - prints unsigned octa nums
 * @arg_list: List of args
 * @arr_buffer: buffer array to handle print
 * @flags: active flags
 * @width: get width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Num of chars that is printed.
*/
int print_octa_num(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size)
{
    int i = BUFFER_SIZE - 2;
    unsigned long int num = va_arg(arg_list, unsigned int);
    unsigned long int new_num = num;
    (void)width;
    num = convert_unsigned_int(num, size);

    if (num == 0)
        arr_buffer[i--] = '0';
    arr_buffer[BUFFER_SIZE - 1] = '\0';
    while (num > 0)
    {
        arr_buffer[i--] = (num % 8) + '0';
        num /= 8;
    }
    if (flags & FLAG_HASH && new_num != 0)
        arr_buffer[i--] = '0';
    i++;

    return (write_unsigned_int(1, i, arr_buffer, flags, width, prec, size));
}

/**
 * lowercase_hex_num - prints hexadecimal 
 * nums in small letters
 * @arg_list: List of args
 * @arr_buffer: buffer array to handle print
 * @flags: active flags
 * @width: get width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Num of chars that is printed.
*/
int lowercase_hex_num(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size)
{
    return (hex_num(arg_list, "0123456789abcdef", arr_buffer, flags, 'x', width, prec, size));
}

/**
 * uppercase_hex_num - prints hexadecimal nums
 * in uppercase
 * @arg_list: List of args
 * @arr_buffer: buffer array to handle print
 * @flags: active flags
 * @width: get width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Num of chars that is printed.
*/
int uppercase_hex_num(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size)
{
    return (hex_num(arg_list, "0123456789ABCDEF", arr_buffer, flags, 'X', width, prec, size));
}

/**
 * print_hex_num - prints hexadecimal nums
 * in uppercase or lowercase
 * @arg_list: List of args
 * @arr_map: values to map num to 
 * @arr_buffer: buffer array to handle print
 * @flags: active flags
 * @char_flag: active flags
 * @width: get width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Num of chars that is printed.
*/
int print_hex_num(va_list arg_list, char arr_map[], char arr_buffer[], int flags, char char_flag, int width, int prec, int size)
{
     int i = BUFFER_SIZE - 2;
    unsigned long int num = va_arg(arg_list, unsigned int);
    unsigned long int new_num = num;
    (void)width;
    num = convert_unsigned_int(num, size);

    if (num == 0)
        arr_buffer[i--] = '0';
    arr_buffer[BUFFER_SIZE - 1] = '\0';

    while (num > 0)
    {
        arr_buffer[i--] = arr_map[num % 16];
        num = num /16;
    }
    if (flags & FLAG_HASH && new_num != 0)
    {
        arr_buffer[i--] = char_flag;
        arr_buffer[i--] = '0';
    }
    i++;
    
    return (write_unsigned_int(0, i, arr_buffer, flags, width, prec, size));
}