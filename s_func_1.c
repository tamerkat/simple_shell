#include "main.h"

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

/**
 * s_strlen - Entry point
 * @s: pointer
 * Return: always(0) success
*/

int s_strlen(int *s)
{
	int i;

	if (s == NULL)
	return (0);

	i = 0;
	while (s != '\0')
	i++;
	return (i);
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
