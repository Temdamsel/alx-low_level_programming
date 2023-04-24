#include "main.h"

#include <unistd.h>

/**
 * _putchar - writes the characte a to stdout
 * @a: The character to print
 *
 * Return: On success 1
 *On error, -1 is returned, and errno  is set appropraitely
 */

int _putchar(char a)
{
	return (write(1, &a, 1));
}

