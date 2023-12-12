#include "shell.h"

/**
 * freee - Entry point
 * @ptr:	double pointer
 * Return: (0)
*/
void freee(char **ptr)
{
	char **pptr = ptr;

	if (!ptr)
		return;
	while (*ptr)
		free(*ptr++);
	free(pptr);
}

/**
 * freeb - Entry point
 * @p: pointer
 * Return: (0)
*/
int freeb(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}

/**
 * list_free - Entry point
 * @new_head: pointer
 * Return: (0)
*/
void list_free(node_t **new_head)
{
	node_t *nnode, *node_next, *hhead;

	if (!new_head || !*new_head)
		return;
	hhead = *new_head;
	nnode = hhead;
	while (nnode)
	{
		node_next = nnode->next;
		free(nnode->s);
		free(nnode);
		nnode = node_next;
	}
	*new_head = NULL;
}

