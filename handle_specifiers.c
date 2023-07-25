#include <stddef.h>
#include "main.h"

/**
 * print_char - Prints a character to stdout.
 *
 * @c: The character to be printed.
 *
 * Return: The number of characters printed.
 */
int print_char(char c)
{
        return (_putchar(c));
}

/**
 * print_string - Prints a string to stdout.
 *
 * @str: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_string(const char *str)
{
	int printed_chars = 0;
	const char *ptr = str;
        if (str == NULL)
                str = "(null)";

        while (*ptr)
        {
                _putchar(*ptr);
                printed_chars++;
                ptr++;
        }
        return (printed_chars);
}

/**
 * print_int - Prints an integer to stdout.
 *
 * @num: The integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_int(int num)
{
	char buffer[20];
	int length = 0;
        /* Handle negative numbers */
        if (num < 0)
        {
                _putchar('-');
                num = -num;
        }

        /* Convert the integer to a string in reverse order */
	do {
                buffer[length++] = '0' + (num % 10);
                num /= 10;
        } while (num > 0);

        /* Print the string in reverse order */
        while (length > 0)
        {
                _putchar(buffer[length - 1]);
                length--;
        }
        return (length);
}

