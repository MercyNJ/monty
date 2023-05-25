#include "monty.h"

/**
* perform_pchar - Outputs the character at top of stack,
* then a new line
* @head: stack head
* @count: line count
*
* Return: nothing
*/
void perform_pchar(stack_t **head, unsigned int count)
{
        stack_t *h;

        h = *head;
        if (!h)
        {
                fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
                fclose(montyState.file);
                free(montyState.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        if (h->n > 127 || h->n < 0)
        {
                fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
                fclose(montyState.file);
                free(montyState.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        printf("%c\n", h->n);
}
