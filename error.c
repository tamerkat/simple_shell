#include "shell.h"

/**
 * s_eputchar - Entry point
 * @c: character
 * Return: always succuss (0)
*/
int s_eputchar(char c)
{
	static char buffer[BUFFER_SIZE];
	static int j;

	if (c == FLUSH_BUFFER_SIZE || j >= BUFFER_SIZE)
	{
		write(2, buffer, j);
		j = 0;
	}
	if (c != FLUSH_BUFFER_SIZE)
		buffer[j++] = c;
	return (1);
}



/**
 * s_eput - Entry point
 * @s: string
 * Return: always succuss (0)
*/
void s_eput(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		s_eputchar(s[i]);
		i++;
	}
}


/**
 * s_err_atoi - Entry point
 * @str: pointer
 * Return: (0)
*/
int s_err_atoi(char *str)
{
	unsigned long int ret = 0;
	int i = 0;

	if (*str == '+')
		str++;
	for (i = 0;	str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			ret *= 10;
			ret += (str[i] - '0');
			if (ret > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (ret);
}

/**
 * error_print - Entry point
 * @data: pointer
 * @str: pointer
 * Return: (0)
*/
void error_print(data_t *data, char *str)
{
	s_eput(data->fname);
	s_eput(": ");
	print_e(data->line_count, STDERR_FILENO);
	s_eput(": ");
	s_eput(data->argv[0]);
	s_eput(": ");
	s_eput(str);
}

/**
 * print_e - Entry point
 * @in: number
 * @file: number
 * Return: (0)
*/
int print_e(int in, int file)
{
	int (*__putchar)(char) = s_putchar;
	unsigned int _pro_;
	int j;
	int count = 0;
	unsigned int r;

	if (file == STDERR_FILENO)
		__putchar = s_eputchar;
	if (in < 0)
	{
		_pro_ = -in;
		__putchar('-');
		count++;
	}
	else
		_pro_ = in;
	r = _pro_;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (_pro_ / j)
		{
			__putchar('0' + r / j);
			count++;
		}
		r %= j;
	}
	__putchar('0' + r);
	count++;

	return (count);
}

