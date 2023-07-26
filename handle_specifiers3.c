#include <stddef.h>
#include "main.h"
#include <unistd.h>

/**
 * print_memory_address - Prints the memory address of a pointer.
 * @ptr: The pointer whose memory address is to be printed.
 *
 * Return: The number of characters printed.
 */
int print_memory_address(void *ptr)
{
	unsigned long int address = (unsigned long int)ptr;
	int printed_chars = 0;
	char buffer[1024];
	int buffer_index = 0;
	int remainder = address % 16;

	if (remainder < 10)
		buffer[buffer_index++] = '0' + remainder;
	else
		buffer[buffer_index++] = 'a' + remainder - 10;

	address /= 16;

	do {
		remainder = address % 16;
		buffer[buffer_index++] = remainder < 10 ? '0' + remainder : 'a' + remainder - 10;
		address /= 16;
	} while (address > 0);


	if (buffer[0] != '0')
	{
		buffer[0] = '0';
		buffer[1] = 'x';
		buffer_index += 1;
	}

	for (buffer_index--; buffer_index >= 0; buffer_index--)
	{
		write(1, &(buffer[buffer_index]), 1);
		printed_chars++;
	}
	return (printed_chars);
}

/**
 * print_reversed_string - Prints a string in reverse order.
 * @str: The input string.
 *
 * Return: The number of characters printed.
 */
int print_reversed_string(const char *str)
{
	int printed_chars = 0;
	int i;
	int length;

	if (str == NULL)
		str = "(null)";

	while (str[length])
		length++;

	for (i = length - 1; i >= 0; i--)
	{
		write(1, &(str[i]), 1);
		printed_chars++;
	}
	return (printed_chars);
}
/**
 * print_rot13_string - Prints a string using ROT13 encryption.
 * @str: The input string.
 *
 * Return: The number of characters printed.
 */
int print_rot13_string(const char *str)
{
	int printed_chars = 0;
	char buffer[1024];
	int buffer_index = 0;
	char c;
	char base;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		c = *str;

		if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		{
			base = (c >= 'a') ? 'a' : 'A';

			c = base + ((c - base + 13) % 26);
		}

		buffer[buffer_index++] = c;
		printed_chars++;

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

