#include "shell.h"

/**
 * print_node_list - Entry point
 * @h: double pointer
 * Return: always true
*/
size_t print_node_list(const node_t *h)
{
	size_t i;

	i = 0;
	while (h)
	{
	s_put(convert_num(h->n, 10, 0));
	s_putchar(':');
	s_putchar(' ');
	s_put(h->s ? h->s : "(nil)");
	s_put("\n");
	h = h->next;
	i++;
	}
	return (i);
}


/**
 * printf_node_list -Entry point
 * @h: double pointer
 * Return: always true
*/
size_t printf_node_list(const node_t *h)
{
	size_t i;

	i = 0;
	while (h)
	{
	s_put(h->s ? h->s : "(nil)");
	s_put("\n");
	h = h->next;
	i++;
	}
	return (i);
}

/**
 * del_node_index -Entry point
 * @head: double pointer
 * @index: double pointer
 * Return: always true
*/
int del_node_index(node_t **head, unsigned int index)
{
	node_t *node, *b_node;
	unsigned int i;

	if (!head || !*head)
	return (0);
	if (!index)
	{
	node = *head;
	*head = (*head)->next;
	free(node->s);
	free(node);
	return (1);
	}
	node = *head;
	while (node)
	{
	if (i == index)
	{
	b_node->next = node->next;
	free(node->s);
	free(node);
	return (1);
	}
	i++;
	b_node = node;
	node = node->next;
	}
	return (0);
}


/**
 * add_node_head -Entry point
 * @head: double pointer
 * @str: pointer
 * @num: number
 * Return: always true
*/
node_t *add_node_head(node_t **head, char *str, int num)
{
	node_t *new_node;

	if (!head)
	return (NULL);
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
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
/**
 * get_index_node - Entry point
 * @hhead: Entry point
 * @nnode: Entry point
 * Return: (0)
*/
ssize_t get_index_node(node_t *hhead, node_t *nnode)
{
	size_t j = 0;

	while (hhead)
	{
		if (hhead == nnode)
			return (j);
		hhead = hhead->next;
		j++;
	}
	return (-1);
}

