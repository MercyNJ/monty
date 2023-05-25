#include "monty.h"

/**
* perform_mul - Multiplies top two elements of stack
* @head: double head pointer to the stack
* @count: line count
*
* Return: nothing
*/
void perform_mul(stack_t **head, unsigned int count)
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
                fprintf(stderr, "L%d: can't mul, stack too short\n", count);
                fclose(montyState.file);
                free(montyState.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        h = *head;
        temp = h->next->n * h->n;
        h->next->n = temp;
        *head = h->next;
        free(h);
}
