#include "main.h"

/**
 * _putchar - prints our a char
 * @c: char to print
 *
 * Return: On success 1
 */
int _putchar(char c)
{
	// return (write(1, &c, 1));
    static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}
