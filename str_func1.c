#include "shell.h"

/**
 * s_strlen - Entry point
 * @str: pointer
 * Return: always(0) success
*/

int s_strlen(char *str)
{
	int i = 0;

	if (!str)
	return (0);

	while (str++)
	i++;
	return (i);
}

/**
 * s_strcpy - Entry point
 * @dest: pointer
 * @src: pointer
 * Return: always(0) success
*/

char *s_strcpy(char *dest, char *src)
{
	int digit;

	digit = 0;
	if (dest == src || !*src)
	return (dest);

	while (src[digit])
	dest[digit++] = src[digit++];

	dest[digit] = 0;
	return (dest);
}


/**
 * s_strncat - Entry point
 * @dest: pointer
 * @src: pointer
 * @len: number length of destination
 * Return: always(0) success
*/
char *s_strncat(char *dest, char *src, int len)
{
	int i = 0, j = 0;
	char *str = dest;

	while (dest[i] != '\0')
	i++;
	while (src[j] != '\0' && j < len)
	dest[i++] = src[j++];
	if (j < len)
	dest[j] = '\0';
	return (str);
}


/**
 * s_putfd - Entry point
 * @s: character
 * @file: int
 * Return:(0)
*/
int s_putfd(char s, int file)
{
	static char buffer[BUFFER_SIZE];
	static int j;

	if (s == FLUSH_BUFFER_SIZE || j >= BUFFER_SIZE)
	{
		write(file, buffer, j);
		j = 0;
	}
	if (s != FLUSH_BUFFER_SIZE)
		buffer[j++] = s;
	return (1);
}


/**
 * s_putsfd - Entry point
 * @s: pointer
 * @file: number
 * Return: (0)
*/
int s_putsfd(char *s, int file)
{
	int j = 0;

	if (!s)
		return (0);
	while (*s)
	{
		j += s_putfd(*s++, file);
	}
	return (j);
}

