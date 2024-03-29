#include "monty.h"

/**
* perform_rotl- Rotates the stack to the top
* @head: head of the stack
* @count: line count
*
* Return: nothing
*/
void perform_rotl(stack_t **head,  __attribute__((unused)) unsigned int count)
{
        stack_t *tmp = *head, *aux;

        if (*head == NULL || (*head)->next == NULL)
        {
                return;
        }
        aux = (*head)->next;
        aux->prev = NULL;
        while (tmp->next != NULL)
        {
                tmp = tmp->next;
        }
        tmp->next = *head;
        (*head)->next = NULL;
        (*head)->prev = tmp;
        (*head) = aux;
}
