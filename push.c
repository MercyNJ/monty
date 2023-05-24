#include "monty.h"

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
