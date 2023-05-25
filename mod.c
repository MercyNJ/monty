#include "monty.h"

/**
* perform_mod - Calculates remainder of division of 2nd
* top element of stack by top element of the stack
* @head: double head pointer to the stack
* @count: line count
*
* Return: nothing
*/
void perform_mod(stack_t **head, unsigned int count)
{
        stack_t *h;
        int len = 0, temp;

        h = *head;
        while (h)
        {
                h = h->next;
                len++;
        }
        if (len < 2)
        {
                fprintf(stderr, "L%d: can't mod, stack too short\n", count);
                fclose(montyState.file);
                free(montyState.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        h = *head;
        if (h->n == 0)
        {
                fprintf(stderr, "L%d: division by zero\n", count);
                fclose(montyState.file);
                free(montyState.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        temp = h->next->n % h->n;
        h->next->n = temp;
        *head = h->next;
        free(h);
}
