#include "main.h"

/**
 * _puts - prints a string and a new line main
 * @str: pointer to a string to prin
 *
 * Return: Always 0 (Success)
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
