#include "shell.h"
/**
 * convert_num -Entry point
 * @num: long Number
 * @start: Number
 * @end: Number
 * Return: (0)
*/
char *convert_num(long int num, int start, int end)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(end & convertNumber_positive) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = end & converNum_lower ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % start];
		n /= start;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * delim_is - Entry point
 * @c: character
 * @del: pointer
 * Return: (0)
*/
int delim_is(char c, char *del)
{
	while (*del)
		if (*del++ == c)
			return (1);
	return (0);
}


/**
 * s_strtow - Entry point
 * @str: pointer
 * @ptr: pointer
 * Return: (0)
*/
char **s_strtow(char *str, char *ptr)
{
	int digit1, digit2, n, c, woednum = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!ptr)
		ptr = " ";
	for (digit1 = 0; str[digit1] != '\0'; digit1++)
		if (!delim_is(str[digit1], ptr) && (delim_is(str[digit1 + 1], ptr)
		|| !str[digit1 + 1]))
			wordnum++;

	if (wordnum == 0)
		return (NULL);
	s = malloc((1 + wordnum) * sizeof(char *));
	if (!s)
		return (NULL);
	for (digit1 = 0, digit2 = 0; digit2 < wordnum; digit2++)
	{
		while (delim_is(str[digit1], ptr))
			digit1++;
		c = 0;
		while (!delim_is(str[digit1 + c], ptr) && str[digit1 + c])
			c++;
		s[digit2] = malloc((c + 1) * sizeof(char));
		if (!s[digit2])
		{
			for (c = 0; c < digit2; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < c; n++)
			s[digit2][n] = str[digit1++];
		s[digit2][n] = 0;
	}
	s[digit2] = NULL;
	return (s);
}

/**
 * char_dup -Entry point
 * @pathstr: pointer
 * @in: number
 * @to: number
 * Return: (0)
*/
char *char_dup(char *pathstr, int in, int to)
{
	static char buffer[1024];
	int j = 0, r = 0;

	for (r = 0, j = in; j < to; j++)
		if (pathstr[j] != ':')
			buffer[r++] = pathstr[j];
	buffer[r] = 0;
	return (buffer);
}

