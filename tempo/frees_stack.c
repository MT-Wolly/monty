#include "monty.h"

/**
  * frees_stack - Releases all elements in the stack
  * Return: Nothing
  */
void frees_stack(void)
{
	stack_t *tmp = NULL;

	if (head)
	{
		tmp = head;

		while (tmp)
		{
			head = head->next;
			free(tmp);
			tmp = head;
		}
	}
}
