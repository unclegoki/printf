#include "main.h"

/**
 * pointer_printer - prints unsigned nums
 * @arg_list: List of args
 * @arr_buffer: buffer array to handle print
 * @flags: active flags
 * @width: get width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Num of chars that is printed.
*/
int pointer_printer(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size)
{
    char x = 0, padding = ' ';
    int i = BUFFER_SIZE - 2, len = 2, start_padding = 1;
    unsigned long address_of_num;
    char arr_map[] = "01234567abcdef";
    void *the_address = va_arg(arg_list, void *);

    (void)width;
    (void)size;
    if (the_address == NULL)
        return (write(1, "(nil)", 5));
    arr_buffer[BUFFER_SIZE - 1] = '\0';
    (void)prec;
    address_of_num = (unsigned long)the_address;

    while (address_of_num > 0)
    {
        arr_buffer[i--] = arr_map[address_of_num % 16];
        address_of_num /= 16;
        len++;
    }
    if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
        padding = '0';
    if (flags & FLAG_PLUS)
        x = '+', len++;
    else if (flags & FLAG_SPACE)
        x = ' ', len++;

    i++;
    return (write_ptr(arr_buffer, i, len, width, flags, padding, x, start_padding));
}

/**
 * print_ascii - prints ascii of non
 * printable chars in hex
 * @arg_list: List of args
 * @arr_buffer: buffer array to handle print
 * @flags: active flags
 * @width: get width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Num of chars that is printed.
*/
int print_ascii(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size)
{
    int i, x = 0;
    char *str = va_arg(arg_list, char *);
    (void)size;
    (void)width;
    (void)flags;
    (void)prec;
    if (str == NULL)
        return (write(1, "(null)", 6));
    while (str[i] != '\0')
    {
        if (printable(str[i]))
            arr_buffer[i + x] = str[i];
        else
            x += append_hex(str[i], arr_buffer, i + x);
        i++;
    }
    arr_buffer[i + x] = '\0';
    return (write(1, arr_buffer, i + x));
}

/**
 * print_reverse_str - prints reverse string
 * @arg_list: List of args
 * @arr_buffer: buffer array to handle print
 * @flags: active flags
 * @width: get width
 * @prec: Precision specifier
 * @size: Size specifier
 * Return: Num of chars that is printed.
*/
int print_reverse_str(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size)
{
    char *s;
    int i, j, counter = 0;
    (void)size;
    (void)arr_buffer;
    (void)flags;
    (void)width;

    s = va_arg(arg_list, char *);
    if (s == NULL)
    {
        (void)prec;
        s = "(null)";
    }
    while (s[i])
        i++;
    for (j = i - 1; j >= 0; j--)
        putchar(s[j]);
    return (i);
}

/**
 * print_rot13 - prints string in rot13
 * @arg_list: List of args
 * @flags: active flags
 * Return: length of string that is printed.
*/
int print_rot13(va_list arg_list, char arr_buffer[], int flags, int width, int prec, int size)
{
   char x;
	char *str;
	unsigned int i, j;
	int counter = 0;
	char text_in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char text_out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(arg_list, char *);
	(void)prec;
	(void)flags;
	(void)width;
	(void)arr_buffer;
	(void)size;

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; text_in[j]; j++)
		{
			if (text_in[j] == str[i])
			{
				x = text_out[j];
				write(1, &x, 1);
				counter++;
				break;
			}
		}
		if (!text_in[j])
		{
			x = str[i];
			write(1, &x, 1);
			counter++;
		}
	}
	return (counter);

}