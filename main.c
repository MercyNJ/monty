#include "monty.h"
#include <stdio.h>
#define _GNU_SOURCE
#include <stdlib.h>

montyState_t montyState = {NULL, NULL, NULL, 0};

/**
* main - Entry for monty code interpreter
* @argc: argument count
* @argv: argument value
*
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
        char *content;
        FILE *file;
        size_t size = 0;
        ssize_t read_line = 1;
        stack_t *stack = NULL;
        unsigned int count = 0;

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        file = fopen(argv[1], "r");
        montyState.file = file;
        if (!file)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }
        while (read_line > 0)
        {
                content = NULL;
                read_line = getline(&content, &size, file);
                montyState.content = content;
                count++;
                if (read_line > 0)
                {
                        execute(content, &stack, count, file);
                }
                free(content);
		 }
        free_stack(stack);
        fclose(file);
return (0);
}
