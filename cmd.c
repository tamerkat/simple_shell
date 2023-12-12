#include "shell.h"


/**
 * cmd_is -Entry point
 * @data: pointer
 * @lol: pointer
 * Return: (0)
*/
int cmd_is(data_t *data, char *lol)
{
	struct stat st;

	(void)data;
	if (!lol || stat(lol, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}


/**
 * cmd_fork - Entry point
 * @data: pointer
 * Return: (0)
*/
void cmd_fork(data_t *data)
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("Error:");
		return;
	}
	if (child == 0)
	{
		if (execve(data->path, data->argv, environ_get(data)) == -1)
		{
			free_data(data, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(data->status));
	}
}


/**
 * cmd_find - Entry point
 * @data: pointer
 * Return: (0)
*/
void cmd_find(data_t *data)
{
	int r;
	int j;
	char *lol = NULL;

	data->path = data->argv[0];
	if (data->line_count_flag == 1)
	{
		data->line_count++;
		data->line_count_flag = 0;
	}
	for (j = 0, r = 0; data->arg[j]; j++)
		if (!delim_is(data->arg[j], " \t\n"))
			r++;
	if (!r)
		return;

	lol = path_find(data, s_getenv(data, "PATH="), data->argv[0]);
	if (lol)
	{
		data->path = lol;
		cmd_fork(data);
	}
	else
	{
		if ((interactive_mood(data) || s_getenv(data, "PATH=")
					|| data->argv[0][0] == '/') && cmd_is(data, data->argv[0]))
			cmd_fork(data);
		else if (*(data->arg) != '\n')
		{
			data->status = 127;
			error_print(data, "not found\n");
		}
	}
}

