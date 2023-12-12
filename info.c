#include "shell.h"

/**
 * clear_data - Entry point
 * @data: pointer
 * Return: 0
*/
void clear_data(data_t *data)
{
	data->path = NULL;
	data->argc = 0;
	data->arg = NULL;
	data->argv = NULL;
}


/**
 * get_info - Entry point
 * @data: pointer
 * Return: 0
*/
ssize_t get_info(data_t *data)
{
	static size_t digit1, digit2, lenght;
	ssize_t t = 0;
	char **buffer_t = &(data->arg), *ptr;
	static char *buffer;

	s_putchar(FLUSH_BUFFER_SIZE);
	t = input_buffer(data, &buffer, &lenght);
	if (t == -1)
		return (-1);
	if (lenght)
	{
		digit2 = digit1;
		ptr = buffer + digit1;

		check_i(data, buffer, &digit2, digit1, lenght);
		while (digit2 < lenght)
		{
			if (is_cheak(data, buffer, &digit2))
				break;
			digit2++;
		}

		digit1 = digit2 + digit1;
		if (digit1 >= lenght)
		{
			digit1 = lenght = 0;
			data->cmd_buf_type = NORM_CMD;
		}

		*buffer_t = ptr;
		return (s_strlen(ptr));
	}

	*buffer_t = buffer;
	return (t);
}

/**
 * input_buffer - Entry point
 * @data: pointer
 * @buffer: double pointer
 * @length: size
 * Return: (0)
*/
ssize_t input_buffer(data_t *data, char **buffer, size_t *length)
{
	size_t len_i = 0;
	ssize_t i = 0;

	if (!*length)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigint_Handel);
#if GETLINE
		i = getline(buffer, &len_i, stdin);
#else
		i = s_getline(data, buffer, &len_i);
#endif
		if (i > 0)
		{
			if ((*buffer)[i - 1] == '\n')
			{
				(*buffer)[i - 1] = '\0';
				i--;
			}
			data->line_count_flag = 1;
			comment_remove(*buffer);
			build_his_list(data, *buffer, data->hist_count++);
			{
				*length = i;
				data->cmd_buf = buffer;
			}
		}
	}
	return (i);
}

/**
 * set_data - Entry point
 * @data: pointer
 * @av: double pointe
 * Return: (0)
*/
void set_data(data_t *data, char **av)
{
	int j = 0;

	data->fname = av[0];
	if (data->arg)
	{
		data->argv = s_strtow(data->arg, " \t");
		if (!data->argv)
		{
			data->argv = malloc(sizeof(char *) * 2);
			if (data->argv)
			{
				data->argv[0] = s_strdup(data->arg);
				data->argv[1] = NULL;
			}
		}
		for (j = 0; data->argv && data->argv[j]; j++)
			;
		data->argc = j;

		alias_replace(data);
		var_replace(data);
	}
}

/**
 * free_data - Entry point
 * @data: pointer
 * @all: number
 * Return: (0)
*/
void free_data(data_t *data, int all)
{
	freee(data->argv);
	data->argv = NULL;
	data->path = NULL;
	if (all)
	{
		if (!data->cmd_buf)
			free(data->arg);
		if (data->env)
			list_free(&(data->env));
		if (data->history)
			list_free(&(data->history));
		if (data->alias)
			list_free(&(data->alias));
		freee(data->environs);
			data->environs = NULL;
		freeb((void **)data->cmd_buf);
		if (data->read_fd > 2)
			close(data->read_fd);
		s_putchar(FLUSH_BUFFER_SIZE);
	}
}

