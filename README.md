## Authors: Kelvin Carrington Tichana, Nana Owusu

## Project title: _printf

## Details:

_printf is a custom printf function that is similar to the printf function from the stdio.h library. It supports the following specifiers:

d or i: Prints the value of an integer as a decimal number.
c: Prints the value of a character as a character.
s: Prints the value of a string as a string.
%: Prints a literal % character.
b: Prints the value of an unsigned integer as a binary number.
x or X: Prints the value of an unsigned integer as a hexadecimal number.
o: Prints the value of an unsigned integer as an octal number.
u: Prints the value of an unsigned integer as an unsigned decimal number.
r: Prints the value of a string in reverse order.
p: Prints the address of a pointer as a hexadecimal number.
To use _printf, simply include the main.h header file in your program and call the _printf() function with the format string and the arguments that you want to print. For example, the following code would print the value of the integer variable x as a decimal number:

c
#include "main.h"

int main() {
int x = 10;
_printf("%d\n", x);
return 0;
}


The output of the code would be:

10

Usage:

To use _printf, you must include the main.h header file in your program. Then, you can call the _printf() function with the format string and the arguments that you want to print. The format string is a string that tells _printf how to format the output. For example, the format string %d tells _printf to print the value of an integer as a decimal number.

The arguments that you pass to _printf() are the values that you want to print. The arguments can be of any type, including integers, characters, strings, and pointers.

For more information, please see the man page.
