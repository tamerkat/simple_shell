#include "main.h"

/**
 * *s_strcat - Entry point
 * @dest: pointer
 * @src: pointer
 * Return: always(0) success
*/

char *s_strcat(char *dest, char *src)
{
	char *str = dest;

	while (*dest)
		*dest++;
	while (*src)
		*dest++ = *src++;

	*dest = *src;
	return (str);
}


/**
 * s_strchr - Entry point
 * @dest: pointer
 * @src: character
 * Return: always(0) success
*/

char *s_strchr(char *dest, char src)
{
	do {
	if (*dest == src)
	return (dest);
	} while (*dest++ != '\0');
	return (NULL);
}

/**
 * s_strncpy - Entry point
 * @dest: pointer
 * @src: pointer
 * @len: number length
 * Return: always(0) success
*/

char *s_strncpy(char *dest, char *src, int len)
{
	int i = 0, j;
	char *str = dest;

	while (src[i] != '\0' && i < len - 1)
		dest[i++] = src[i++];
	if (i < len)
	{
		j = i;
		while (j < len)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (str);
}


/**
 * s_strcmp - Entry point
 * @str1: pointer
 * @str2: pointer
 * Return: always(0) success
*/

int s_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		*str1++;
		*str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 > *str2 ? 1 : -1);
}
