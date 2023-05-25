#include "monty.h"

/**
* perform_sub - Substracts nodes
* @head: double head pointer to the stack
* @count: line count
*
* Return: nothing
*/
void perform_sub(stack_t **head, unsigned int count)
{
        stack_t *temp;
        int sub, nd;

        temp = *head;
        for (nd = 0; temp != NULL; nd++)
                temp = temp->next;
        if (nd < 2)
        {
                fprintf(stderr, "L%d: can't sub, stack too short\n", count);
                fclose(montyState.file);
                free(montyState.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        temp = *head;
        sub = temp->next->n - temp->n;
        temp->next->n = sub;
        *head = temp->next;
        free(temp);
}
