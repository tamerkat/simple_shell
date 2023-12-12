#include "shell.h"

/**
 * interactive_mood - Entry point
 * @data: pointer
 * Return: 0
*/
int interactive_mood(data_t *data)
{
	return (isatty(STDIN_FILENO) && data->read_fd <= 2);
}

