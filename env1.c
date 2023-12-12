#include "shell.h"

/**
 * s_env_set - Entry point
 * @data: pointer
 * @let: pointer
 * @result: pointer
 * Return: (0)
*/
int s_env_set(data_t *data, char *let, char *result)
{
	char *buf = NULL;
	node_t *node;
	char *p;

	if (!let || !result)
		return (0);

	buf = malloc(s_strlen(let) + s_strlen(result) + 2);
	if (!buf)
		return (1);
	s_strcpy(buf, let);
	s_strcat(buf, "=");
	s_strcat(buf, result);
	node = data->env;
	while (node)
	{
		p = s_start_w(node->s, let);
		if (p && *p == '=')
		{
			free(node->s);
			node->s = buf;
			data->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(data->env), buf, 0);
	free(buf);
	data->env_changed = 1;
	return (0);
}

/**
 * s_getenv - Entry point
 * @data: pointer
 * @host: char
 * Return: (0)
*/
char *s_getenv(data_t *data, const char *host)
{
	node_t *node = data->env;
	char *ptr;

	while (node)
	{
		ptr = s_start_w(node->s, host);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}



/**
 * s_un_setenv - Entry point
 * @data: pointer
 * @let: pointer
 * Return: (0)
*/
int s_un_setenv(data_t *data, char *let)
{
	size_t j = 0;
	node_t *node = data->env;
	char *ptr;

	if (!node || !let)
		return (0);

	while (node)
	{
		ptr = s_start_w(node->s, let);
		if (ptr && *ptr == '=')
		{
			data->env_changed = del_node_index(&(data->env), j);
			j = 0;
			node = data->env;
			continue;
		}
		node = node->next;
		j++;
	}
	return (data->env_changed);
}

/**
 * environ_get - Entry point
 * @data: pointer
 * Return: (0)
*/
char **environ_get(data_t *data)
{
	if (!data->environs || data->env_changed)
	{
		data->environs = s_list_to_str(data->env);
		data->env_changed = 0;
	}
	return (data->environs);
}

