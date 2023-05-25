#include "monty.h"

/**
* perform_stack - Prints the top
* @head: head of stack
* @count: line count
*
* Return: nothing
*/
void perform_stack(stack_t **head, unsigned int count)
{
        (void)head;
        (void)count;
        montyState.stack_mode = 0;
}

/**
* addnode - Adds node to the head stack
* @head: head of the stack
* @n: new value
*
* Return: nothing
*/
void addnode(stack_t **head, int n)
{
        stack_t *new_node, *temp;

        temp = *head;
        new_node = malloc(sizeof(stack_t));
        if (new_node == NULL)
        { printf("Error\n");
                exit(0); }
        if (temp)
                temp->prev = new_node;
        new_node->n = n;
        new_node->next = *head;
        new_node->prev = NULL;
        *head = new_node;
}
