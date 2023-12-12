#include "shell.h"

/**
 * alias_replace - Entry point
 * @data: pointer
 * Return: (0)
*/
int alias_replace(data_t *data)
{
	node_t *node;
	int j;
	char *c;

	for (j = 0; j < 10; j++)
	{
		node = node_start_w(data->alias, data->argv[0], '=');
		if (!node)
			return (0);
		free(data->argv[0]);
		c = s_strchr(node->s, '=');
		if (!c)
			return (0);
		c = s_strdup(c + 1);
		if (!c)
			return (0);
		data->argv[0] = c;
	}
	return (1);
}


/**
 * var_replace - Entry point
 * @data: pointer
 * Return: (0)
*/
int var_replace(data_t *data)
{
	int j = 0;
	node_t *node;

	for (j = 0; data->argv[j]; j++)
	{
		if (data->argv[j][0] != '$' || !data->argv[j][1])
			continue;

		if (!s_strcmp(data->argv[j], "$?"))
		{
			str_rep(&(data->argv[j]),
					s_strdup(convert_num(data->status, 10, 0)));
			continue;
		}
		if (!s_strcmp(data->argv[j], "$$"))
		{
			str_rep(&(data->argv[j]),
					s_strdup(convert_num(getpid(), 10, 0)));
			continue;
		}
		node = node_start_w(data->env, &data->argv[j][1], '=');
		if (node)
		{
			str_rep(&(data->argv[j]),
					s_strdup(s_strchr(node->s, '=') + 1));
			continue;
		}
		str_rep(&data->argv[j], s_strdup(""));
	}
	return (0);
}

/**
 * s_aliasme - Entry point
 * @data: pointer
 * Return: (0)
*/
int s_aliasme(data_t *data)
{
	int j = 0;
	char *ptr = NULL;
	node_t *node = NULL;

	if (data->argc == 1)
	{
		node = data->alias;
		while (node)
		{
			alias_print(node);
			node = node->next;
		}
		return (0);
	}
	for (j = 1; data->argv[j]; j++)
	{
		ptr = s_strchr(data->argv[j], '=');
		if (ptr)
			s_alias_set(data, data->argv[j]);
		else
			alias_print(node_start_w(data->alias, data->argv[j], '='));
	}
	return (0);
}

