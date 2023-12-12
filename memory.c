#include "shell.h"

/**
 * s_memset - Entry point
 * @s: pointer
 * @a: character
 * @n: number
 * Return: always success (0)
*/
char *s_memset(char *s, char a, unsigned int n)
{
	int i;

	for (i = 0; i < n; i++)
		s[i] = a;
	return (s);
}


/**
 * s_realloc -Entry point
 * @ptrr: pointer
 * @size_old: pointer
 * @size_new: pointer
 * Return: always success (0)
*/
void *s_realloc(void *ptrr, unsigned int size_old, unsigned int size_new)
{
	char *i;

	if (!ptrr)
		return (malloc(size_new));
	if (!size_new)
		return (free(ptrr), NULL);
	if (size_new == size_old)
		return (ptrr);

	i = malloc(size_new);
	if (!i)
		return (NULL);

	size_old = size_old < size_new ? size_old : size_new;
	while (size_old--)
		i[size_old] = ((char *)ptrr)[size_old];
	free(ptrr);
	return (i);
}

