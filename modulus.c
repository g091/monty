#include "monty.h"

/**
 * m_mod - gets the modulus of division of 2 no.s.
 * @stack: pointer to a list
 * @n_line: line no. of the op command
 */

void m_mod(stack_t **stack, unsigned int n_line)
{
	int n = 0;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}

	n += (*stack)->n;
	m_pop(stack, n_line);
	if (n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n_line);
		exit(EXIT_FAILURE);
	}

	(*stack)->n %= n;
}
