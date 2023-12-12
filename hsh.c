#include "shell.h"

/**
 * hsh - shell command line interface
 * @data: pointer
 * @argv: double pointer
 * Return: always (0) succuss
*/
int hsh(data_t *data, char **argv)
{
	ssize_t i = 0;
	int result = 0;

	while (i != -1 && result != -2)
	{
		clear_data(data);
		if (interactive_mood(data))
			s_put("$ ");
		s_eputchar(FLUSH_BUFFER_SIZE);
		i = get_info(data);
		if (i != -1)
		{
			set_data(data, argv);
			result = builtin_find(data);
			if (result == -1)
				cmd_find(data);
		}
		else if (interactive_mood(data))
			s_putchar('\n');
		free_data(data, 0);
	}
	his_write(data);
	free_data(data, 1);
	if (!interactive_mood(data) && data->status)
		exit(data->status);
	if (result == -2)
	{
		if (data->err_num == -1)
			exit(data->status);
		exit(data->err_num);
	}
	return (result);
}

