#include "main.h"

/**
 * append_text_to_file - it append text to the end of a file
 * @text_content: string to add to the file end
 * @filename: points to the name of the file
 * Return: if the function fail or filename is NULL --1
 * if the file does not exit, user lack write permissions --1
 * else -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int f, k, lent = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (lent = 0; text_content[lent];)
			lent++;
	}
	f = open(filename, O_WRONLY | O_APPEND);
	k = write(f, text_content, lent);

	if (f == -1 || k == -1)
		return (-1);
	close(f);

	return (1);
}
