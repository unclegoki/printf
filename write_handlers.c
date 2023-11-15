#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char arr_buffer[], int flags, int width, int precision, int size)
{ /* char is stored at left and paddingind at buffer's right */
	int i = 0;
	char padding = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FLAG_ZERO)
		padding = '0';

	arr_buffer[i++] = c;
	arr_buffer[i] = '\0';

	if (width > 1)
	{
		arr_buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			arr_buffer[BUFFER_SIZE - i - 2] = padding;

		if (flags & FLAG_MINUS)
			return (write(1, &arr_buffer[0], 1) +
					write(1, &arr_buffer[BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &arr_buffer[BUFFER_SIZE - i - 1], width - 1) +
					write(1, &arr_buffer[0], 1));
	}

	return (write(1, &arr_buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char arr_buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFFER_SIZE - ind - 1;
	char padding = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		padding = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & FLAG_PLUS)
		extra_ch = '+';
	else if (flags & FLAG_SPACE)
		extra_ch = ' ';

	return (write_num(ind, arr_buffer, flags, width, precision,
		len, padding, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padding: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char arr_buffer[],
	int flags, int width, int prec,
	int length, char padding, char extra_c)
{
	int i, padding_start = 1;

	if (prec == 0 && ind == BUFFER_SIZE - 2 && arr_buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFFER_SIZE - 2 && arr_buffer[ind] == '0')
		arr_buffer[ind] = padding = ' '; /* width is displayed with paddinging ' ' */
	if (prec > 0 && prec < length)
		padding = ' ';
	while (prec > length)
		arr_buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			arr_buffer[i] = padding;
		arr_buffer[i] = '\0';
		if (flags & FLAG_MINUS && padding == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				arr_buffer[--ind] = extra_c;
			return (write(1, &arr_buffer[ind], length) + write(1, &arr_buffer[1], i - 1));
		}
		else if (!(flags & FLAG_MINUS) && padding == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				arr_buffer[--ind] = extra_c;
			return (write(1, &arr_buffer[1], i - 1) + write(1, &arr_buffer[ind], length));
		}
		else if (!(flags & FLAG_MINUS) && padding == '0')/* extra char to left of padding */
		{
			if (extra_c)
				arr_buffer[--padding_start] = extra_c;
			return (write(1, &arr_buffer[padding_start], i - padding_start) +
				write(1, &arr_buffer[ind], length - (1 - padding_start)));
		}
	}
	if (extra_c)
		arr_buffer[--ind] = extra_c;
	return (write(1, &arr_buffer[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char arr_buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFFER_SIZE - ind - 1, i = 0;
	char padding = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFFER_SIZE - 2 && arr_buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padding = ' ';

	while (precision > length)
	{
		arr_buffer[--ind] = '0';
		length++;
	}

	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		padding = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			arr_buffer[i] = padding;

		arr_buffer[i] = '\0';

		if (flags & FLAG_MINUS) /* Asign extra char to left of buffer [buffer>padding]*/
		{
			return (write(1, &arr_buffer[ind], length) + write(1, &arr_buffer[0], i));
		}
		else /* Asign extra char to left of paddinging [padding>buffer]*/
		{
			return (write(1, &arr_buffer[0], i) + write(1, &arr_buffer[ind], length));
		}
	}

	return (write(1, &arr_buffer[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padding: Char representing the paddinging
 * @extra_c: Char representing extra char
 * @padding_start: Index at which paddinging should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char arr_buffer[], int ind, int length,
	int width, int flags, char padding, char extra_c, int padding_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			arr_buffer[i] = padding;
		arr_buffer[i] = '\0';
		if (flags & FLAG_MINUS && padding == ' ')/* Asign extra char to left of buffer */
		{
			arr_buffer[--ind] = 'x';
			arr_buffer[--ind] = '0';
			if (extra_c)
				arr_buffer[--ind] = extra_c;
			return (write(1, &arr_buffer[ind], length) + write(1, &arr_buffer[3], i - 3));
		}
		else if (!(flags & FLAG_MINUS) && padding == ' ')/* extra char to left of buffer */
		{
			arr_buffer[--ind] = 'x';
			arr_buffer[--ind] = '0';
			if (extra_c)
				arr_buffer[--ind] = extra_c;
			return (write(1, &arr_buffer[3], i - 3) + write(1, &arr_buffer[ind], length));
		}
		else if (!(flags & FLAG_MINUS) && padding == '0')/* extra char to left of padding */
		{
			if (extra_c)
				arr_buffer[--padding_start] = extra_c;
			arr_buffer[1] = '0';
			arr_buffer[2] = 'x';
			return (write(1, &arr_buffer[padding_start], i - padding_start) +
				write(1, &arr_buffer[ind], length - (1 - padding_start) - 2));
		}
	}
	arr_buffer[--ind] = 'x';
	arr_buffer[--ind] = '0';
	if (extra_c)
		arr_buffer[--ind] = extra_c;
	return (write(1, &arr_buffer[ind], BUFFER_SIZE - ind - 1));
}
