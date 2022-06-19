#define _GNU_SOURCE
#include "monty.h"

/**
 * read_file - reads & gets the command
 * @fd: no. of arguments
 * @file_name: file name
 * Return: nothing.
 */

void read_file(FILE *fd, char *file_name)
{
	int n_line = 1;
	size_t size_buf = 1;
	char *buffer = NULL, *delim = " \t\n", *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *stack = NULL;
	(void) file_name;

	while (getline(&buffer, &size_buf, fd) != -1)
	{
		opcode = strtok(buffer, delim);
		if (!opcode || opcode[0] == '#')
		{
			n_line++;
			continue;
		}
		f = opcode_func(opcode);
		if (!f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", n_line, opcode);
			exit(EXIT_FAILURE);
		}
		f(&stack, n_line);
		n_line++;
	}
	free(buffer);
	free_dlistint(stack);
	fclose(fd);
}

/**
 * opcode_func - gets the opcode function
 * @s: input
 * Return: nothing
 */

void (*opcode_func(char *s))(stack_t **stack, unsigned int n_line)
{
	instruction_t opc[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{NULL, NULL}
	};
	int i = 0;

	for (; opc[i].opcode; i++)
	{
		if (strcmp(s, opc[i].opcode) == 0)
			return (opc[i].f);
	}
	return (NULL);
}

/**
 * _isdigit - checks if it;s a no.
 * @c: input
 * Return: 1 if it's a no. 0 if not
 */

int _isdigit(char *c)
{
	int i;

	for (i = 0; c[i]; i++)
	{
		if (c[i] < 48 || c[i] > 57)
			return (0);
	}
	return (1);
}

/**
 * free_dlistint - frees the linked list
 * @head: pointer to the beginning of the linked list
 * Return: nothing
 */

void free_dlistint(stack_t *head)
{
	stack_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

/**
 * rm_head - deletes head node
 * @head: pointer to list
 */

void rm_head(stack_t **head)
{
	stack_t *temp = *head, *temp_d = NULL;

	temp_d = temp;
	if ((*temp).next != NULL)
		(*temp).next->prev = NULL;
	*head = (*temp).next;
	free(temp_d);
}

