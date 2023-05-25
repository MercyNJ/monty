#include "monty.h"

/**
* perform_pall - prints all stack's elements
* @head: double head pointer to the stack
* @count: unused line count
*
* Return: nothing
*/
void perform_pall(stack_t **head, unsigned int count)
{
        stack_t *h;
        (void)count;

        h = *head;
        if (h == NULL)
                return;
        while (h)
        {
                printf("%d\n", h->n);
                h = h->next;
        }
}
