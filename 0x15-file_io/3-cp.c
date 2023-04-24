#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocate 1024 bytes for a buffer
 * @file: the name of the file the buffer is storing file for
 * Return: the pointer to the new allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: cant write to %s\n", file);
		exit(99);
	}
	return (buffer);
}
/**
 * close_file - Closes the file description
 * @fd: file to be closed
 */

void close_file(int fd)
{
	int x;

	x = close(fd);

	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cant close xd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies contents of file to another file
 * @argc: the number of arguments supplied to the program
 * @argv: an array of pointers to the argument
 * Return: when successful 0
 *
 * Description: if an argument is not correct - exit code 97.
 * if file_from doesnt exist or maybe cant be read exit code 98.
 * if file_to cant be created or written to - exit code 99
 * if file_to of file_from cant be close - exit code 100,
 */
int main(int argc, char *argv[])
{
	int from, to, a, x;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	}
	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	a = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || a == -1)
		{
			dprintf(STDERR_FILENO, "Error: cant read file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}
		x = write(to, buffer, a);
		if (to == -1 || x == -1)
		{
			dprintf(STDERR_FILENO, "Error: cant write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		a = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (a > 0);
	free(buffer);
	close_file(from);
	close_file(to);
	return (0);
}
