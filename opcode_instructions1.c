#include "monty.h"

/**
* push - pushes item to the top of stack
* @stack: pointer to the beginning of stack
* @new_nd: value of the new node
* Return: Nothing
*/

stack_t *push(stack_t **stack, int new_nd)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = new_nd;
	if (*stack == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
		return (new);
	}
	else
	{
		new->prev = NULL;
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
		return (new);
	}
	return (NULL);
}

/**
* pall - prints all the content of the stack
* @stack: pointer to the beginning of the stack
* @line_number: unused
* Return: Nothing
*/

void pall(stack_t **stack, unsigned int __attribute__((__unused__))line_number)
{
	stack_t *head = *stack;

	while (head != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", head->n);
		head = head->next;
	}
}

/**
* pint - prints the value at the top of the stack
* @stack: pointer to the beginning of the stack
* @line_number: the line number of the bytecode
* Return: Nothing
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}
	dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}

/**
* pop - removes element at the top of the stack
* @stack: pointer to the beginning of the stack
* @line_number: the line number of the bytecode
* Return: Nothing
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (head->next != NULL)
	{
		next = head->next;
		next->prev = NULL;
	}
	*stack = head->next;
	free(head);
}

/**
* swap - switches the first top two elements of the stack
* @stack: pointer to the beginning of the stack
* @line_number: the line number of the bytecode
* Return: Nothing
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = (*stack)->next;
	next->prev = NULL;
	(*stack)->next = next->next;
	next->next = *stack;
	(*stack)->prev = next;
	*stack = next;
}
