#include "monty.h"

/**
* mod - remainder of the division of the top two element
* @stack: pointer to the beginning of the stack
* @line_number: line number of the bytecode
* Return: Nothing
*/

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *next, *head = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (head->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = head->next;
	next->n = head->next->n % head->n;
	next->prev = NULL;
	*stack = next;
	free(head);
}

