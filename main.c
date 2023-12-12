#include "shell.h"

/**
 * main - fuction Entry point (func)
 * @ac: number of arguments (num)
 * @av: array of arguments (string)
 * Return: (0)
*/

int main(int ac, char **av)
{
	data_t data[] = {DATA_INFO};
	int file = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (file)
		: "r" (file));

	if (ac == 2)
	{
	file = open(av[1], O_RDONLY);
	if (file == -1)
	{
	if (errno == ENOENT)
	{
	s_eput(av[0]);
	s_put(": 0: ERROR");
	s_eput(av[1]);
	s_eputchar('\n');
	s_putchar(FLUSH_BUFFER_SIZE);
	exit(2);
	}
	if (errno == EACCES)
	{
	exit(127);
	}
	return (EXIT_FAILURE);
	}
	data->read_fd = file;
	}
	s_env_list(data);
	read_his(data);
	hsh(data, av);
	return (EXIT_SUCCESS);
}
