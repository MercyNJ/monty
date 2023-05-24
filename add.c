#include "monty.h"

/**
 * add - It adds top 2 stack elements.
 * @stack: A double pointer to top of stack.
 * @line_number: The line no being executed.
 *
 * Description: If elements less than 2,
 * an error message is printed.
 *
 * Return: Nothing.
 */


void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top1;
	stack_t *top2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = *stack;
	top2 = (*stack)->next;

	top2->n += top1->n;

	pop(stack, line_number);
}
