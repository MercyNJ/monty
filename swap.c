#include "monty.h"

/**
 * swap - Swaps stack's top 2 elements.
 * @stack: Stack's top double pointer.
 * @line_number: Line num to be executed.
 *
 * Description: Necessary pointers are updated,
 * to maintain data structure.
 *
 * Return: Nothing.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top1;
	stack_t *top2;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    top1 = *stack;
    top2 = (*stack)->next;

    top1->next = top2->next;
    if (top2->next != NULL)
        top2->next->prev = top1;

    top2->prev = NULL;
    top2->next = top1;
    top1->prev = top2;

    *stack = top2;
}
