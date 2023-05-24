#include "monty.h"

/**
 * pint - Prints top of the stack value.
 * @stack: Double pointer to stack top.
 * @line_number: Line num being executed.
 *
 * Description: Prints top value without,
 * modifying stack.
 *
 * Return: Nothing.
 */

void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
