#include "shell.h"

/**
 * _puts - print string.
 * @str: recevied string.
 */
void _puts(char *str)
{
	int y;

	for (y = 0; str[y] != '\0'; y++)
	{
		_putchar(str[y]);
	}
	_putchar('\n');
}
/**
 * _putchar - writes the character c to stdout.
 * @c: The character to print
 *
 * Return: On success 1 On error, -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
