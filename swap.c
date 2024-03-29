#include "monty.h"

/**
* perform_swap - Swaps stack's top two elements
* @head: head of stack
* @count: line count
*
* Return: nothing
*/
void perform_swap(stack_t **head, unsigned int count)
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
                fprintf(stderr, "L%d: can't swap, stack too short\n", count);
                fclose(montyState.file);
                free(montyState.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        h = *head;
        temp = h->n;
        h->n = h->next->n;
        h->next->n = temp;
}
