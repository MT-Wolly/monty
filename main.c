#include "monty.h"

/**
* func_call - picks the right operation to be performed
* @cmd: the arguments in file
* @stack: pointer to beginning of stack
* @line_number: line number in byte code
* Return=: 1 if found otherwise 0
*/

int func_call(char *cmd, stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t code[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", divide},
		{"nop", nop},
		{"mod", mod},
		{NULL, NULL}
		};
	i = 0;
	while (code[i].opcode != NULL)
	{
		if (strcmp(code[i].opcode, cmd) == 0)
		{
			code[i].f(stack, line_number);
			break;
		}
	i++;
	}
	if (code[i].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, cmd);
		exit(EXIT_FAILURE);
	}
	return (0);
}


/**
* main - Entry point
* @ac: number of command line argument
* @av: value of command line argument
* Return: Always 0
*/
int main(int ac, char **av)
{
	FILE *fd;
	size_t n = 0;
	int line_number = 0;
	char *cmdl = NULL; 
	char *val = NULL;
	char *line = NULL;
	stack_t *stk = NULL;

	arg_check(ac);
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &n, fd)) != -1)
	{
		line_number++;
		cmdl = strtok(line, " \n\t");
		val = strtok(NULL, " \n\t");
		if (cmdl == NULL || cmdl[0] == '#')
			continue;
		else if (_isdigit(val) == 1 && strcmp("push", cmdl) == 0)
			push(&stk, atoi(val));
		else if (strcmp("push", cmdl) != 0)
			func_call(cmdl, &stk, line_number);
		else if (is_not_digit(val) == 0 || val == NULL)
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	free_stack(stk);
	fclose(fd);
	return (0);
}
