#include "monty.h"

/**
  * count_stack - Counts the number of elements in the stack
  * @stack: The stack to count
  * Return: Number of elements in the stack
  */
unsigned int count_stack(stack_t *stack)
{
	stack_t *curr = stack;
	unsigned int len = 0;

	while (curr != NULL)
	{
		++len;
		curr = curr->next;
	}

	return (len);
}
