#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct montyState_s - variables -args, file, line content
* @arg: Argument count value
* @file: pointer to monty file
* @content: line content
* @stack_mode: flag change stack to queue or viceversa.
*
* Description: carries values through the program
*/
typedef struct montyState_s
{
        char *arg;
        FILE *file;
        char *content;
        int stack_mode;
}  montyState_t;
extern montyState_t montyState;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void perform_push(stack_t **head, unsigned int number);
void perform_pall(stack_t **head, unsigned int number);
void perform_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int count, FILE *file);
void free_stack(stack_t *head);
void perform_pop(stack_t **head, unsigned int count);
void perform_swap(stack_t **head, unsigned int count);
void perform_add(stack_t **head, unsigned int count);
void perform_nop(stack_t **head, unsigned int count);
void perform_sub(stack_t **head, unsigned int count);
void perform_div(stack_t **head, unsigned int count);
void perform_mul(stack_t **head, unsigned int count);
void perform_mod(stack_t **head, unsigned int count);
void perform_pchar(stack_t **head, unsigned int count);
void perform_pstr(stack_t **head, unsigned int count);
void perform_rotl(stack_t **head, unsigned int count);
void perform_rotr(stack_t **head, __attribute__((unused)) unsigned int count);
void addnode(stack_t **head, int n);
void add_to_queue(stack_t **head, int n);
void perform_queue(stack_t **head, unsigned int count);
void perform_stack(stack_t **head, unsigned int count);

#endif
