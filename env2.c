#include "shell.h"

/**
 * s_env_list - Entry point
 * @data: pointer
 * Return: always (0) success
*/
int s_env_list(data_t *data)
{
	node_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	data->env = node;
	return (0);
}



/**
 * s_envme - Entry point
 * @data: pointer
 * Return: (0)
*/
int s_envme(data_t *data)
{
	printf_node_list(data->env);
	return (0);
}





/**
 * s_set_envme - Entry point
 * @data: pointer
 * Return: (0)
*/
int s_set_envme(data_t *data)
{
	if (data->argc != 3)
	{
		s_eput("alot of args\n");
		return (1);
	}
	if (s_env_set(data, data->argv[1], data->argv[2]))
		return (0);
	return (1);
}

/**
 * s_un_setenvme - Entry point
 * @data: pointer
 * Return: (0)
*/
int s_un_setenvme(data_t *data)
{
	int i;

	if (data->argc == 1)
	{
		s_eput("alot of arg.\n");
		return (1);
	}
	for (i = 1; i <= data->argc; i++)
		s_un_setenv(data, data->argv[i]);

	return (0);
}


