#include "monty.h"

stack_t *stack = NULL;

int main(int argc, char *argv[])
{
    FILE *file;
    char line[1024];
    unsigned int line_number = 0;
    char *opcode;
    char *read;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    while ((read = fgets(line, sizeof(line), file)) != NULL)
    {
        line_number++;

        opcode = strtok(line, " \t\n");

        if (opcode != NULL && opcode[0] != '#')
        {
            if (strcmp(opcode, "push") == 0)
                push(&stack, line_number);
            else if (strcmp(opcode, "pall") == 0)
                pall(&stack);
            else if (strcmp(opcode, "pint") == 0)
                pint(&stack, line_number);
            else if (strcmp(opcode, "pop") == 0)
                pop(&stack, line_number);
            else if (strcmp(opcode, "swap") == 0)
                swap(&stack, line_number);
            else if (strcmp(opcode, "add") == 0)
                add(&stack, line_number);
            else if (strcmp(opcode, "nop") == 0)
                nop(&stack, line_number);
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);

    return EXIT_SUCCESS;
}
