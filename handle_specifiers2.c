#include "main.h"
#include <unistd.h>

/**
 * print_hexadecimal_upper - Prints an unsigned integer in uppercase
 *                           hexadecimal format.
 * @num: The unsigned integer to be printed in hexadecimal format.
 *
 * Return: The number of characters printed.
 */
int print_hexadecimal_upper(unsigned int num)
{
	return (print_hexadecimal(num, 0));
}

/**
 * print_special_string - Prints a string with special characters
 *                        escaped in hexadecimal format.
 * @str: The input string.
 *
 * Return: The number of characters printed.
 */
int print_special_string(const char *str)
{
	int printed_chars = 0;
	char buffer[1024];
	int buffer_index = 0;
	char c;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		c = *str;

		if (c < ' ' || c >= 127)
		{
			buffer[buffer_index++] = '\\';
			buffer[buffer_index++] = 'x';
			buffer[buffer_index++] = "0123456789ABCDEF"[(c >> 4) & 0xF];
			buffer[buffer_index++] = "0123456789ABCDEF"[c & 0xF];
			printed_chars += 4;
		}
		else
		{
			buffer[buffer_index++] = c;
			printed_chars++;
		}
		if (buffer_index >= 1020)
		{
			write(1, buffer, buffer_index);
			buffer_index = 0;
		}

		str++;
	}

	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
	}
	return (printed_chars);
}

