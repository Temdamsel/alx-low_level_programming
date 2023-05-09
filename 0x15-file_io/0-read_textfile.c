#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - will read text file and print to stdout
 * @filename: file being read
 * @letters: numbers of the letter to be read
 * Return: actual numbers of bytes and print 0 when functions fails
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *txt;
	ssize_t cd;
	ssize_t y;
	ssize_t p;

	cd = open(filename, O_RDONLY);
	if (cd == -1)
		return (0);

	txt = malloc(sizeof(char) * letters);
	p = read(cd, txt, letters);
	y = write(STDOUT_FILENO, txt, p);
	free(txt);
	close(cd);
	return (y);
}
