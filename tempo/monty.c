#include "monty.h"

stack_t *head = NULL;

/**
  * main - The Monty Interpreter entry point
  * @argn: argument number
  * @args: argument passed to the interpreter
  * Return: Always zero
  */
int main(int argn, char *args[])
{
	FILE *fd = NULL;
	size_t line_len = 0;
	unsigned int line_num = 1;
	int read = 0, op_stat = 0;
	char *filename = NULL, *op_code = NULL, *op_param = NULL, *buffer = NULL;

	filename = args[1];
	check_args_num(argn);
	fd = open_file(filename);

	while ((read = getline(&buffer, &line_len, fd)) != -1)
	{
		op_code = strtok(buffer, "\t\n ");
		if (op_code)
		{
			if (op_code[0] == '#')
			{
				++line_num;
				continue;
			}

			op_param = strtok(NULL, "\t\n ");
			op_stat = handle_execution(op_code, op_param, line_num, op_stat);

			if (op_stat >= 100 && op_stat < 300)
			{
				fclose(fd);
				handle_error(op_stat, op_code, line_num, buffer);
			}
		}

		++line_num;
	}

	frees_stack();
	free(buffer);
	fclose(fd);
	return (0);
}
