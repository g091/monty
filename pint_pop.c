#include "monty.h"

/**
 * m_pint - prints the value at the top
 * @stack: Double pointer input
 * @n_line: line no.
 * Return: nothing
 */

void m_pint(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp = *stack;
	(void)n_line;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", n_line);
		exit(EXIT_FAILURE);
	}

	else if (!stack || !*stack)
		return;
	printf("%i\n", tmp->n);
}

/**
 * m_pop - deletes an item from a stack
 * @stack: pointer to a list
 * @n_line: line no. of the op command
 */

void m_pop(stack_t **stack, unsigned int n_line)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", n_line);
		exit(EXIT_FAILURE);
	}
	else
	{
		rm_head(stack);
	}
}
