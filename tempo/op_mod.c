#iinclude "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int i = 0, j = 0, len = 0;

	len = count_stack(*stack);

	if (len < 2)
		handle_error(ERR_MOD_USG, NULL, line_number, NULL);

	i = temp->n;

	if (i == 0)
		handle_error(ERR_DIV_ZRO, NULL, line_number, NULL);

	j = temp->next->n;
	temp->next->n = j % i;
	*stack = temp->next;
	free(temp);
}
