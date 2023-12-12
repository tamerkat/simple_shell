#include "shell.h"

/**
 * get_his - Entry point for history function
 * @data: Pointer double struct data_t
 * Return: (0)
*/
char *get_his(data_t *data)
{
	char *buffer, *sys;

	sys = s_getenv(data, "HOME=");
	if (!sys)
		return (NULL);
	buffer = malloc(sizeof(char) * (s_strlen(sys) + s_strlen(FILE_HIST) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	s_strcpy(buffer, sys);
	s_strcat(buffer, "/");
	s_strcat(buffer, FILE_HIST);
	return (buffer);
}



/**
 * get_his_file - Entry point
 * @data: pointer
 * Return: (0)
*/
char *get_his_file(data_t *data)
{
	char *buffer;
	char *p;

	p = s_getenv(data, "HOME=");
	if (!p)
		return (NULL);
	buffer = malloc(sizeof(char) * (s_strlen(p) + s_strlen(FILE_HIST) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	s_strcpy(buffer, p);
	s_strcat(buffer, "/");
	s_strcat(buffer, FILE_HIST);
	return (buffer);
}



/**
 * read_his - Entry point
 * @data: pointer
 * Return: always (0) success
*/
int read_his(data_t *data)
{
	int j, line = 0;
	ssize_t file, r, s = 0;
	int end = 0;
	char *buffer = NULL, *name = get_his_file(data);
	struct stat st;

	if (!name)
		return (0);

	file = open(name, O_RDONLY);
	free(name);
	if (s < 2)
		return (0);
	if (file == -1)
		return (0);
	if (!fstat(file, &st))
		s = st.st_size;
	buffer = malloc(sizeof(char) * (s + 1));
	if (!buffer)
		return (0);
	r = read(file, buffer, s);
	buffer[s] = 0;
	if (r <= 0)
		return (free(buffer), 0);
	close(file);
	for (j = 0; j < s; j++)
		if (buffer[j] == '\n')
		{
			buffer[j] = 0;
			build_his_list(data, buffer + end, line++);
			end = j + 1;
		}
	if (end != j)
		build_his_list(data, buffer + end, line++);
	free(buffer);
	data->hist_count = line;
	while (data->hist_count-- >= MAX_HIST)
		del_node_index(&(data->history), 0);
	his_renum(data);
	return (data->hist_count);
}


