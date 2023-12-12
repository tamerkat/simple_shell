#include "shell.h"

/**
 * str_rep - Entry point
 * @old_str: double pointer
 * @new_str: pointer
 * Return: (0)
*/
int str_rep(char **old_str, char *new_str)
{
	free(*old_str);
	*old_str = new_str;
	return (1);
}
/**
 * s_alias_unset - Entry point
 * @data: pointer
 * @s: pointer
 * Return: (0)
*/
int s_alias_unset(data_t *data, char *s)
{
	int result;
	char *ptr, cha;

	ptr = s_strchr(s, '=');
	if (!ptr)
		return (1);
	cha = *ptr;
	*ptr = 0;
	result = del_node_index(&(data->alias),
		get_index_node(data->alias, node_start_w(data->alias, s, -1)));
	*ptr = cha;
	return (result);
}


/**
 * s_alias_set - Entry point
 * @data: pointer
 * @s: pointer
 * Return: (0)
*/
int s_alias_set(data_t *data, char *s)
{
	char *ptr;

	ptr = s_strchr(s, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (s_alias_unset(data, s));

	s_alias_unset(data, s);
	return (add_node_end(&(data->alias), s, 0) == NULL);
}


/**
 * alias_print - Entry point
 * @head: pointer
 * Return: (0)
*/
int alias_print(node_t *head)
{
	char *alia = NULL;
	char *ptr = NULL;

	if (head)
	{
		ptr = s_strchr(head->s, '=');
		for (alia = head->s; alia <= ptr; alia++)
		s_putchar(*alia);
		s_putchar('\'');
		s_put(ptr + 1);
		s_put("'\n");
		return (0);
	}
	return (1);
}
