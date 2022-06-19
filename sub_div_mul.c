#include "monty.h"

/**
 * m_sub - subtracts the top 2 elements of the stack
 * @stack: pointer to a list
 * @n_line: line no. of the op command
 */

void m_sub(stack_t **stack, unsigned int n_line)
{
	int n = 0;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}

	n += (*stack)->n;
	m_pop(stack, n_line);
	(*stack)->n -= n;
}

/**
 * m_div - divides the top 2 elements of the stack.
 * @stack: pointer to a list
 * @n_line: line no. of op command
 */

void m_div(stack_t **stack, unsigned int n_line)
{
	int n = 0;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}

	n += (*stack)->n;
	m_pop(stack, n_line);
	if (n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n_line);
		exit(EXIT_FAILURE);
	}

	(*stack)->n /= n;
}

/**
 * m_mul - multiplies the top 2 elements of the stack.
 * @stack: pointer to a list
 * @n_line: line no. of the op command
 */

void m_mul(stack_t **stack, unsigned int n_line)
{
	int n = 0;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%i: can't mul, stack too short\n", n_line);
		exit(EXIT_FAILURE);
	}

	n += (*stack)->n;
	m_pop(stack, n_line);
	(*stack)->n *= n;
}
