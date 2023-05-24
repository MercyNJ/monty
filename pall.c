#include "monty.h"

/**
 * pall - Outputs/prints all elements of stack.
 * @stack: Double pointer to stack top.
 *
 * Description: Traverses the stack,printing,
 * values,for empty stack prints nothing.
 *
 * Return: Nothing.
 */

void pall(stack_t **stack)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
