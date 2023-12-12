#include "shell.h"

/**
 * sigint_Handel - Entry point
 * @num: Number
 * Return: (0)
*/
void sigint_Handel(__attribute__((unused))int num)
{
	s_put("\n");
	s_put("$ ");
	s_putchar(FLUSH_BUFFER_SIZE);
}

/**
 * read_buffer - Entry point
 * @data: pointer
 * @buffer: pointer
 * @digit: number
 * Return: (0)
*/
ssize_t read_buffer(data_t *data, char *buffer, size_t *digit)
{
	ssize_t i = 0;

	if (*digit)
		return (0);
	i = read(data->read_fd, buffer, BUFFER_SIZE);
	if (i >= 0)
		*digit = i;
	return (i);
}

/**
 * comment_remove - Entry point
 * @buffer: pointer
 * Returns: (0)
*/
void comment_remove(char *buffer)
{
	int j;

	for (j = 0; buffer[j] != '\0'; j++)
		if (buffer[j] == '#' && (!j || buffer[j - 1] == ' '))
		{
			buffer[j] = '\0';
			break;
		}
}



/**
 * s_getline - Entry point
 * @data: pointer
 * @ptr: double pointer
 * @len: number
 * Return: (0)
*/
int s_getline(data_t *data, char **ptr, size_t *len)
{
	char *o = NULL, *new_o = NULL, *c;
	size_t kali;
	static char buffer[BUFFER_SIZE];
	ssize_t ar = 0, ch = 0;
	static size_t i, j;

	o = *ptr;
	if (o && len)
		ch = *len;
	if (i == j)
		i = j = 0;

	ar = read_buffer(data, buffer, &j);
	if (ar == -1 || (ar == 0 && j == 0))
		return (-1);

	c = s_strchr(buffer + i, '\n');
	kali = c ? 1 + (unsigned int)(c - buffer) : j;
	new_o = s_realloc(o, ch, ch ? ch + kali : kali + 1);
	if (!new_o)
		return (o ? free(o), -1 : -1);

	if (ch)
		s_strncat(new_o, buffer + i, kali - i);
	else
		s_strncpy(new_o, buffer + i, kali - i + 1);

	ch += kali - i;
	i = kali;
	o = new_o;

	if (len)
		*len = ch;
	*ptr = o;
	return (ch);
}

