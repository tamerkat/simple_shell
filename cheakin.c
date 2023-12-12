#include "shell.h"


/**
 * check_i - Entry point
 * @data: pointer
 * @buffer: pointer
 * @ptr: pointer
 * @j: pointer
 * @lenght: pointer
 * Return: (0)
*/
void check_i(data_t *data, char *buffer, size_t *ptr, size_t j, size_t lenght)
{
	size_t i = *ptr;

	if (data->cmd_buf_type == AND_CMD)
	{
		if (data->status)
		{
			buffer[j] = 0;
			i = lenght;
		}
	}
	if (data->cmd_buf_type == OR_CMD)
	{
		if (!data->status)
		{
			buffer[j] = 0;
			i = lenght;
		}
	}
	*ptr = i;
}


/**
 * is_cheak -Entry point
 * @data: pointer
 * @buffer: pointer
 * @ptr: pointer
 * Return: (0)
*/
int is_cheak(data_t *data, char *buffer, size_t *ptr)
{
	size_t i = *ptr;

	if (buffer[i] == '|' && buffer[i + 1] == '|')
	{
		buffer[i] = 0;
		i++;
		data->cmd_buf_type = OR_CMD;
	}
	else if (buffer[i] == '&' && buffer[i + 1] == '&')
	{
		buffer[i] = 0;
		i++;
		data->cmd_buf_type = AND_CMD;
	}
	else if (buffer[i] == ';')
	{
		buffer[i] = 0;
		data->cmd_buf_type = CHAIN_CMD;
	}
	else
		return (0);
	*ptr = i;
	return (1);
}

