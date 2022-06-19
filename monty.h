#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int n_line);
} instruction_t;


void read_file(FILE *fd, char *file_name);
void (*opcode_func(char *s))(stack_t **stack, unsigned int n_line);
int _isdigit(char *c);
size_t dlistint_len(const stack_t *h);
void free_dlistint(stack_t *head);
void rm_head(stack_t **head);

void m_push(stack_t **stack, unsigned int n_line);
void m_pall(stack_t **stack, unsigned int n_line);
void m_pint(stack_t **stack, unsigned int n_line);
void m_pop(stack_t **stack, unsigned int n_line);
void m_swap(stack_t **stackk, unsigned int n_line);
void m_add(stack_t **stack, unsigned int n_line);
void m_nop(stack_t **stack, unsigned int n_line);
void m_sub(stack_t **stack, unsigned int n_line);
void m_div(stack_t **stack, unsigned int n_line);
void m_mul(stack_t **stack, unsigned int n_line);

#endif
