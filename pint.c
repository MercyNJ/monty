#include "monty.h"

/**
* perform_pint - Outputs the top of the stack
* @head: double head pointer to the stack
* @count: line count
*
* Return: nothing
*/
void perform_pint(stack_t **head, unsigned int count)
{
        if (*head == NULL)
        {
                fprintf(stderr, "L%u: can't pint, stack empty\n", count);
                fclose(montyState.file);
                free(montyState.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        printf("%d\n", (*head)->n);
}
