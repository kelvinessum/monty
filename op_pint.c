#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the instruction in the file
 *
 * If the stack is empty, print error and exit with status EXIT_FAILURE
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
