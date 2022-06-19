#include "monty.h"

/**
 * dlistint_len - count the no. of nodes in the linked list
 * @h: pointer to the beginning of the linked list
 * Return: no. of nodes
 */

size_t dlistint_len(const stack_t *h)
{
	size_t i;

	for (i = 0; h != NULL; i++)
		h = h->next;
	return (i);
}
