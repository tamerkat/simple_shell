#include "shell.h"

/**
 * add_node_end -Entry point
 * @head: double pointer
 * @str: pointer
 * @num: number
 * Return: always true
*/
node_t *add_node_end(node_t **head, char *str, int num)
{
	node_t *new_node, *node;

	if (!head)
	return (NULL);
	node = *head;
	new_node = malloc(sizeof(node_t));
	if (!new_node)
	return (NULL);
	s_memset((void *)new_node, 0, sizeof(node_t));
	new_node->n = num;
	if (str)
	{
	new_node->s = s_strdup(str);
	if (!new_node->s)
	{
	free(new_node);
	return (NULL);
	}
	}
	if (node)
	{
	while (node->next)
	node = node->next;
	node->next = new_node;
	}
	else
	*head = new_node;
	return (new_node);
}


/**
 * free_node - Entry point
 * @head: double pointer
 * Return: always true
*/
void free_node(node_t **head)
{
	node_t *node, *next_node, *hhead;

	if (!head || !*head)
	return;
	hhead = *head;
	node = hhead;
	while (node)
	{
	next_node = node->next;
	free(node->s);
	free(node);
	node = next_node;
	}
	*head = NULL;
}

/**
 * s_list_len - Entry point
 * @h: double pointer
 * Return: always true
*/
size_t s_list_len(node_t *h)
{
	size_t i;

	i = 0;
	while (h)
	{
	h = h->next;
	i++;
	}
	return (i);
}

/**
 * s_list_to_str - Entry point
 * @head: double pointer
 * Return: always true
*/
char **s_list_to_str(node_t *head)
{
	node_t *node = head;
	size_t i = s_list_len(head);
	size_t j;
	char **s;
	char *str;

	if (!head || !i)
		return (NULL);
	s = malloc(sizeof(char *) * (i + 1));
	if (!s)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(s_strlen(node->s) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(s[j]);
			free(s);
			return (NULL);
		}

		str = s_strcpy(str, node->s);
		s[i] = str;
	}
	s[i] = NULL;
	return (s);
}

/**
 * node_start_w - Entry point
 * @node: pointer
 * @pro: pointer
 * @s: string
 * Return: (0)
*/
node_t *node_start_w(node_t *node, char *pro, char s)
{
	char *ptr = NULL;

	while (node)
	{
		ptr = s_start_w(node->s, pro);
		if (ptr && ((s == -1) || (*ptr == s)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

