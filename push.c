#include "monty.h"

/**
* perform_push - Adds node to the stack
* @head: double head pointer to the stack
* @count: line count
*
* Return: nothing
*/
void perform_push(stack_t **head, unsigned int count)
{
        int i, m = 0, flag = 0;

        if (montyState.arg)
        {
                if (montyState.arg[0] == '-')
                        m++;
                for (; montyState.arg[m] != '\0'; m++)
                {
                        if (montyState.arg[m] > 57 || montyState.arg[m] < 48)
                                flag = 1; }
                if (flag == 1)
                { fprintf(stderr, "L%d: usage: push integer\n", count);
                        fclose(montyState.file);
                        free(montyState.content);
                        free_stack(*head);
                        exit(EXIT_FAILURE); }}
        else
        { fprintf(stderr, "L%d: usage: push integer\n", count);
                fclose(montyState.file);
                free(montyState.content);
                free_stack(*head);
                exit(EXIT_FAILURE); }
        i = atoi(montyState.arg);
        if (montyState.stack_mode == 0)
                addnode(head, i);
        else
                add_to_queue(head, i);
}
