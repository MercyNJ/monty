#include "monty.h"

/**
 * push - Pushes an element to stack's top.
 * @stack: A double pointer to stack's top.
 * @line_number: Line num to be executed.
 *
 * Description: New element is dynamically allocated,
 * stack updated to point to newest element.
 *
 * Return: Nothing.
 */

void push(stack_t **stack, unsigned int line_number)
{
    char *token;
    int value;
    stack_t *newNode;

    token = strtok(NULL, " \t\n");
    if (token == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(token);

    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->n = value;
    newNode->prev = NULL;
    newNode->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = newNode;

    *stack = newNode;
}
