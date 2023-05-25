#include "monty.h"

/**
* execute - Main function that executes the opcode
* @stack: head stack linked list
* @count: line count
* @file: pointer to monty file stream
* @content: line content
*
* Return: nothing
*/
int execute(char *content, stack_t **stack, unsigned int count, FILE *file)
{
        instruction_t opcodes_array[] = {
                                {"push", perform_push}, {"pall", perform_pall}, {"pint", perform_pint},
                                {"pop", perform_pop},
                                {"swap", perform_swap},
                                {"add", perform_add},
                                {"nop", perform_nop},
                                {"sub", perform_sub},
                                {"div", perform_div},
                                {"mul", perform_mul},
                                {"mod", perform_mod},
                                {"pchar", perform_pchar},
                                {"pstr", perform_pstr},
                                {"rotl", perform_rotl},
                                {"rotr", perform_rotr},
                                {"queue", perform_queue},
                                {"stack", perform_stack},
                                {NULL, NULL}
                                };
        unsigned int i = 0;
        char *op;

        op = strtok(content, " \n\t");
        if (op && op[0] == '#')
                return (0);
        montyState.arg = strtok(NULL, " \n\t");
        while (opcodes_array[i].opcode && op)
        {
                if (strcmp(op, opcodes_array[i].opcode) == 0)
                {       opcodes_array[i].f(stack, count);
                        return (0);
                }
                i++;
		}
        if (op && opcodes_array[i].opcode == NULL)
        { fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
                fclose(file);
                free(content);
                free_stack(*stack);
                exit(EXIT_FAILURE);
       	}
        return (1);
}
