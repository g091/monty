#include "monty.h"

/**
 * m_push - pushes an element to the stack
 * @stack: double pointer input
 * @n_line: line no.
 * Return: nothing.
 */

void m_push(stack_t **stack, unsigned int n_line)
{
	stack_t *node;
	char delim[] = " \n\t";
	char *s;
	int num, flag, sign = 1;

	s = strtok(NULL, delim);
	if (!s)
	{
		fprintf(stderr, "L%d: usage: push integer\n", n_line);
		exit(EXIT_FAILURE);
	}
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	flag = _isdigit(s);
	if (flag == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", n_line);
		exit(EXIT_FAILURE);
	}
	num = atoi(s) * sign;
	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = num;
	node->next = *stack;
	node->prev = NULL;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}

/**
 * m_pall - prints all the values on the stack
 * @stack: double pointer input
 * @n_line: line no.
 * Return: nothing.
 */

void m_pall(stack_t **stack, unsigned int n_line)
{
	stack_t *tmp = *stack;
	(void)n_line;

	if (!stack || !*stack)
		return;
	while (tmp)
	{
		printf("%i\n", tmp->n);
		tmp = tmp->next;
	}
}
