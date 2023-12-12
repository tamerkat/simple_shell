#include "shell.h"

/**
 * path_find - Entry point
 * @data: pointer
 * @str: pointer
 * @cd: pointer
 * Return: (0)
*/
char *path_find(data_t *data, char *str, char *cd)
{
	char *pather;
	int j = 0;
	int r = 0;

	if (!str)
		return (NULL);
	if ((s_strlen(cd) > 2) && s_start_w(cd, "./"))
	{
		if (cmd_is(data, cd))
			return (cd);
	}
	while (1)
	{
		if (!str[j] || str[j] == ':')
		{
			pather = char_dup(str, r, j);
			if (!*pather)
				s_strcat(pather, cd);
			else
			{
				s_strcat(pather, "/");
				s_strcat(pather, cd);
			}
			if (cmd_is(data, pather))
				return (pather);
			if (!str[j])
				break;
			r = j;
		}
		j++;
	}
	return (NULL);
}

