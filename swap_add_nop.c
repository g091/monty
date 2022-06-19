#include "monty.h"

/**
 * m_swap - swaps the top 2 elements of the stack
 * @stackk: pointer to a list
 * @n_line: line number of op command
 */

void m_swap(stack_t **stackk, unsigned int n_line)
{
	int x, y;

	if (dlistint_len(*stackk) < 2)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}
	x = (*stackk)->n;
	y = (*stackk)->next->n;
	(*stackk)->n = y;
	(*stackk)->next->n = x;
}

/**
 * m_add - adds the top 2 elements of the stack
 * @stack: pointer to a list
 * @n_line: line no. of the op command
 */

void m_add(stack_t **stack, unsigned int n_line)
{
	int n = 0;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}

	n += (*stack)->n;
	m_pop(stack, n_line);
	(*stack)->n += n;
}

/**
 * m_nop - doesn’t do anything
 * @stack: double pointer input
 * @n_line: line no.
 * Return: nothing
 */

void m_nop(stack_t **stack, unsigned int n_line)
{
	(void)**stack;
	(void)n_line;
}
