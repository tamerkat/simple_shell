#include "shell.h"

/**
 * s_histme - Entry point
 * @data: pointer
 * Return: (0)
*/
int s_histme(data_t *data)
{
	printf_node_list(data->history);
	return (0);
}

/**
 * his_renum - Entry point
 * @data: pointer
 * Return: (0)
*/
int his_renum(data_t *data)
{
	int j = 0;
	node_t *node = data->history;

	while (node)
	{
		node->n = j++;
		node = node->next;
	}
	return (data->hist_count = j);
}



/**
 * build_his_list - Entry point
 * @data: pointer
 * @buffer: pointer
 * @line: number
 * Return: (0)
*/
int build_his_list(data_t *data, char *buffer, int line)
{
	node_t *node = NULL;

	if (data->history)
		node = data->history;
	add_node_end(&node, buffer, line);

	if (!data->history)
		data->history = node;
	return (0);
}

/**
 * his_write - Entry point
 * @data: pointer
 * Return: (0)
*/
int his_write(data_t *data)
{
	char *name = get_his(data);
	node_t *node = NULL;
	ssize_t file;

	if (!name)
		return (-1);

	file = open(name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(name);
	if (file == -1)
		return (-1);
	for (node = data->history; node; node = node->next)
	{
		s_putsfd(node->s, file);
		s_putfd('\n', file);
	}
	s_putfd(FLUSH_BUFFER_SIZE, file);
	close(file);
	return (1);
}
