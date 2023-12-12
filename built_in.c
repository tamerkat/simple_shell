#include "shell.h"

/**
 * s_exitme - Entry point
 * @data: pointer
 * Return: (0)
*/
int s_exitme(data_t *data)
{
	int exit;

	if (data->argv[1])
	{
		exit = s_err_atoi(data->argv[1]);
		if (exit == -1)
		{
			data->status = 2;
			error_print(data, "ERROR NUMBER: ");
			s_eput(data->argv[1]);
			s_eputchar('\n');
			return (1);
		}
		data->err_num = s_err_atoi(data->argv[1]);
		return (-2);
	}
	data->err_num = -1;
	return (-2);
}

/**
 * s_helpme - Entry point
 * @data: pointer
 * Return: (0)
*/
int s_helpme(data_t *data)
{
	char **argv_arr;

	argv_arr = data->argv;
	s_put("help works. func not work \n");
	if (0)
		s_put(*argv_arr);
	return (0);
}

/**
 * s_cdme - Entry point
 * @data: pointer
 * Return: (0)
*/
int s_cdme(data_t *data)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		s_put("getcwd fail msgg here\n");
	if (!data->argv[1])
	{
		dir = s_getenv(data, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = s_getenv(data, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (s_strcmp(data->argv[1], "-") == 0)
	{
		if (!s_getenv(data, "OLDPWD="))
		{
			s_put(s);
			s_putchar('\n');
			return (1);
		}
		s_put(s_getenv(data, "OLDPWD=")), s_putchar('\n');
		chdir_ret =
			chdir((dir = s_getenv(data, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(data->argv[1]);
	if (chdir_ret == -1)
	{
		error_print(data, "can't cd to ");
		s_eput(data->argv[1]), s_eputchar('\n');
	}
	else
	{
		s_env_set(data, "OLDPWD", s_getenv(data, "PWD="));
		s_env_set(data, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}




/**
 * builtin_find - Entry point
 * @data: pointer
 * Return: (0)
*/
int builtin_find(data_t *data)
{
	int i, built_in_ret = -1;
	builtin_t built_in[] = {
		{"exit", s_exitme},
		{"env", s_envme},
		{"help", s_helpme},
		{"history", s_histme},
		{"setenv", s_set_envme},
		{"unsetenv", s_un_setenvme},
		{"cd", s_cdme},
		{"alias", s_aliasme},
		{NULL, NULL}
	};
}
