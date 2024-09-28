#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the instruction in the file
 *
 * If the stack contains less than two elements, print error and exit
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	first->next = second->next;
	if (first->next != NULL)
		first->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}
