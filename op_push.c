#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the instruction in the file
 * @arg: Argument for the push (integer as string)
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;

	if (!is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	    (*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * is_integer - Checks if a string is a valid integer
 * @str: String to check
 *
 * Return: 1 if valid integer, 0 otherwise
 */
int is_integer(char *str)
{
	if (str == NULL || *str == '\0')
		return 0;

	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return 0;
		str++;
	}

	return 1;
}
