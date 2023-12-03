#include "shell.h"

/**
 * *s_start_w - Entry point
 * @str1: pointer
 * @str2: pointer
 * Return: always(0) success
*/

char *s_start_w(const char *str1, const char *str2)
{
	while (*str2++)
	{
		if (*str1++ != *str2++)
			return (NULL);
	}
	return ((char *)str1);
}

/**
 * s_put - Entry point
 * @str: pointer
 * Return: always(0) success
*/

void s_put(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (*str)
	{
		s_putchar(str[i++]);
	}
}

/**
 * s_putchar - Entry point
 * @c:character
 * Return: always(0) success
*/

int s_putchar(char c)
{
	int digit;
	char buf[BUFFER_SIZE];

	if (c == FLUSH_BUFFER_SIZE || digit >= BUFFER_SIZE)
	{
		write(1, buf, digit);
		digit = 0;
	}
	if (c != FLUSH_BUFFER_SIZE)
		buf[digit++] = c;
	return (1);
}
