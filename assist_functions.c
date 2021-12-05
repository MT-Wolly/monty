#include "monty.h"

/**
* arg_check - checks the number of arguments
* @ak: number of commandline arguments
* Return: Nothing
*/

void arg_check(int ak)
{
	if (ak != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
* free_stack - frees the stack
* @stk: pointer to the beginning of the stack
* Return: Nothing
*/

void free_stack(stack_t *stk)
{
	stack_t *next;

	while (stk != NULL)
	{
		next = stk->next;
		free(stk);
		stk = next;
	}
}

/**
* _isdigit - checks if a charcter is a number in a string
* @str: string to be searched
* Return: 1 if found, else 0
*/

int _isdigit(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
	}
	return (0);
}

/**
* is_not_digit - checks if string contains values that are not digits
* @str: string to be checked
* Return: 1 if found
*/

int is_not_digit(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}
	return (0);
}
