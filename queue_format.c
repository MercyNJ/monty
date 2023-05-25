#include "monty.h"


/**
* perform_queue - Prints the top of the queue
* @head: head of queue
* @count: line count
*
* Return: nothing
*/
void perform_queue(stack_t **head, unsigned int count)
{
        (void)head;
        (void)count;
        montyState.stack_mode = 1;
}

/**
* add_to_queue - Add node to the tail the queue
* @n: new value
* @head: head of the queue
*
* Return: nothing
*/
void add_to_queue(stack_t **head, int n)
{
        stack_t *new_node, *temp;

        temp = *head;
        new_node = malloc(sizeof(stack_t));
        if (new_node == NULL)
        {
                printf("Error\n");
        }
        new_node->n = n;
        new_node->next = NULL;
        if (temp)
        {
                while (temp->next)
                        temp = temp->next;
        }
        if (!temp)
        {
                *head = new_node;
                new_node->prev = NULL;
        }
        else
		{
                temp->next = new_node;
                new_node->prev = temp;
       		}
}
