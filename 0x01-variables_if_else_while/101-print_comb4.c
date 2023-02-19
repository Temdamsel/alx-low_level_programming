#include <stdio.h>
/**
 * main - Prints all possible different combinations of three digits
 *
 * Return: Always 0
 */
int main(void)
{
	int a, b, i;

	for (a = 0; a < 8; a++)
	{
		for (b = a + 1; b < 9; b++)
		{
			for (i = b + 1; i < 10; i++)
			{
				putchar((a % 10) + '0');
				putchar((b % 10) + '0');
				putchar((i % 10) + '0');
				if (a == 7 && b == 8 && i == 9)
					continue;
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
