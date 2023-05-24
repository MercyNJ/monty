#include "monty.h"

/**
 * pop - Removes stack's top element.
 * @stack: Double pointer to stack's top.
 * @line_number: The line num being executed.
 *
 * Description: Stack is modifies to point,
 * to new top element after removal.
 *
 * Return: Nothing.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    top = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(top);
}
