#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the instruction in the file
 *
 * If the stack contains less than two elements, print error and exit
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	sum = temp->n + temp->next->n;

	pop(stack, line_number);
	(*stack)->n = sum;
}
