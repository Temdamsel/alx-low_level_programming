#include "main.h"
/**
 * append_text_to_file - it append text to the end of a file
 * @text_content: string to add the file end
 * @filename: points to the name of the file
 * Return: if the funct fail or filename is NULL --1
 * if the file does not exist, user lack write permissions --1
 * else -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int a, t, lent = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (lent = 0; text_content[lent];)
			lent++;
	}
	a = open(filename, O_WRONLY | O_APPEND);
	t = write(a, text_content, lent);

	if (a == -1 || t == -1)
		return (-1);
	close(a);

	return (1);
}
