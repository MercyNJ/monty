#include "monty.h"

/**
* perform_pop - Outputs the top of the stack
* @head: double head pointer to the stack
* @count: line count
*
* Return: nothing
*/
void perform_pop(stack_t **head, unsigned int count)
{
        stack_t *h;

        if (*head == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", count);
                fclose(montyState.file);
                free(montyState.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        h = *head;
        *head = h->next;
        free(h);
}
