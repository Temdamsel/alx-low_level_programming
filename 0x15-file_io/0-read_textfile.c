#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - will read text file and print to stdout
 * @filename: file being read
 * @letters: numbers of the letter to be read
 * Return: actual numbers of bytes and print 0 when func fails
 */
ssize_t read_textfile(const  char *filename, size_t letters)
{
	char *txt;
	ssize_t ab;
	ssize_t z;
	ssize_t t;

	ab = open(filename, O_RDONLY);
	if (ab == -1)
		return (0);
	txt = malloc(sizeof(char) * letters);
	t = read(ab, txt, letters);
	z = write(STDOUT_FILENO, txt, t);
	free(txt);
	close(ab);
	return (z);
}
