#include <stddef.h>
#include "main.h"
#include <unistd.h>

/**
 * print_binary - Prints an unsigned integer in binary format.
 * @num: The unsigned integer to be printed in binary format.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int num)
{
	unsigned int binary_digits[32];
	int index = 0;
	int printed_chars = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		binary_digits[index++] = num % 2;
		num /= 2;
	}

	for (index--; index >= 0; index--)
	{
		_putchar('0' + binary_digits[index]);
		printed_chars++;
	}
	return (printed_chars);
}

/**
 * print_octal - Prints an unsigned integer in octal format.
 * @num: The unsigned integer to be printed in octal format.
 *
 * Return: The number of characters printed.
 */
int print_octal(unsigned int num)
{
	char buffer[20];
	int length = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		buffer[length++] = '0' + (num % 8);
		num /= 8;
	}

	for (length--; length >= 0; length--)
	{
		_putchar(buffer[length]);
	}

	return (length + 1);
}

/**
 * print_hexadecimal - Prints an unsigned integer in hexadecimal format.
 * @num: The unsigned integer to be printed in hexadecimal format.
 * @lowercase: A flag indicating whether to use lowercase (1) or uppercase (0).
 *
 * Return: The number of characters printed.
 */
int print_hexadecimal(unsigned int num, int lowercase)
{
	char buffer[20];
	int length = 0;
	char base = lowercase ? 'a' : 'A';
	int printed_chars = 0;
	int remainder = num % 16;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		if (remainder < 10)
			buffer[length++] = '0' + remainder;
		else
			buffer[length++] = base + remainder - 10;

		num /= 16;
	}

	for (length--; length >= 0; length--)
	{
		_putchar(buffer[length]);
		printed_chars++;
	}
	return (printed_chars);
}
