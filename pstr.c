#include "monty.h"

/**
* perform_pstr - Outputs string from top of the stack,
* then a new line.
* @head: head of stack
* @count: line count
*
* Return: nothing
*/
void perform_pstr(stack_t **head, unsigned int count)
{
        stack_t *h;
        (void)count;

        h = *head;
        while (h)
        {
                if (h->n > 127 || h->n <= 0)
                {
                        break;
                }
                printf("%c", h->n);
                h = h->next;
        }
        printf("\n");
}
