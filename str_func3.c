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
	if (*str1++ != *str2++)
	return (NULL);
	return ((char *)str1);
}


/**
 * s_put - Entry point
 * @s: pointer
 * Return: always(0) success
*/
void s_put(char *s)
{
	int j = 0;

	if (!s)
		return;
	while (s[j] != '\0')
	{
		s_putchar(s[j]);
		j++;
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
	char buffer[BUFFER_SIZE];

	if (c == FLUSH_BUFFER_SIZE || digit >= BUFFER_SIZE)
	{
		write(1, buffer, digit);
		digit = 0;
	}
	if (c != FLUSH_BUFFER_SIZE)
		buffer[digit++] = c;
	return (1);
}


/**
 * s_strdup - Entry point
 * @str: pointer
 * Return: always(0) success
*/

char *s_strdup(char *str)
{
	int i = 0;
	char *result;

	if (!str)
	return (NULL);
	while (*str++)
	i++;

	result = (char *)malloc(i + 1);
	if (!result)
	return (NULL);

	for (i++; i--;)
	result[i++] = *--str;

	return (result);
}

