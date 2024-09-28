#include "monty.h"

/**
 * execute_instruction - Finds and executes the correct opcode function
 * @opcode: Opcode to execute
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the file where the opcode is located
 * @arg: Argument for the push instruction, if applicable
 */
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number, char *arg)
{
	instruction_t instructions[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};
	int i = 0;

	if (strcmp(opcode, "push") == 0)
	{

		push(stack, line_number, arg);
		return;
	}

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * free_stack - Frees the stack
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}

/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, exit on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode, *arg;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		arg = strtok(NULL, " \t\n");

		if (opcode == NULL || opcode[0] == '#') /* Ignore comments and blank lines */
			continue;

		execute_instruction(opcode, &stack, line_number, arg);
	}

	free(line);
	free_stack(stack);
	fclose(file);
	return 0;
}
