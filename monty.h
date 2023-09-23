#ifndef MONTY_H
#define MONTY_H

/* Includes */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

/* #MACROS */

#define DEBUG(M) printf("%s%s:%d\n", M, __FILE__, __LINE__);
#define DBG printf("%s:%d\n", __FILE__, __LINE__)
#define FreeVar(var) do { \
	 if (var)\
	{ \
		free(var); \
		var = NULL; \
	} \
} while(0)

#define FREE_2D_ARR(arr) { \
if (arr)\
{ \
		Free_2D_Array(arr); \
		arr = NULL; \
} \
} while(0)
# define IF_NULL_STACK \
{\
	if (!stack || !*stack)\
	{\
		fprintf(stderr, "L%u: can't pop, stack empty\n", line_number);\
		EXIT(stack);\
	}\
}
#define MALLOC(ptr)\
{\
	if (!ptr )\
	{\
		fprintf(stderr, "Error: malloc failed at line %u\n", line_number);\
		EXIT(stack);\
	}\
}
#define STCK_LEN_2 \
{\
	if (stack_len(*stack) < 2)\
	{\
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);\
		EXIT(stack);\
	}\
}

typedef struct n_CATA
{
  int n;
  char **CATA;
  char *command;
  unsigned int line;

}n_CATA ;

/* Data structures */
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
/*""" Global Variables"""*/
/* Commandline Argument Tpokinaized Array*/
extern n_CATA  NCATA;


/*""" Functions Prototype """"*/

/* memory.c*/
size_t Free_2D_Array(char **Array);
void free_stack(stack_t **head);
void EXIT( stack_t **stack);


/* Get_Input.c*/
size_t Get_Inout(char *filePath);



/*String*/
char  **Tokenize_in_Arr(char *string, char*  delim);
size_t Print_2D_Arr(char** array, size_t isNull);
void rm_newLine(char *string);


/* StackManager.c*/
void push( stack_t **stack, unsigned int line_number);
void add( stack_t **stack, unsigned int line_number);
void pall( stack_t **stack, unsigned int line_number);
void swap( stack_t **stack, unsigned int line_number);
void pop( stack_t **stack, unsigned int line_number);
void pint( stack_t **stack, unsigned int line_number);
 void sub(stack_t **stack, unsigned int line_number);
/*opcode_handler.c*/
int *instructionF(  stack_t **list );
bool is_valid_integer(const char *str);

/* Data-Structure.c */
stack_t *creat_One ( int n);
stack_t *Creat_stack_t( int n, stack_t **LIST, int index);
stack_t *creat_One( int n);
int delete_stack_t_at_index(stack_t **head, unsigned int index);
unsigned int Print_stack(const stack_t *h);
unsigned int  stack_len(const stack_t *h);
stack_t *insert_stack_at_index(stack_t **h, unsigned int idx, int n);
stack_t *add_stack_end(stack_t **head, const int n);
stack_t *Add_Head(stack_t **H, int n);
stack_t *add_stack(stack_t **head, const int n);




 ssize_t getline(char **lineptr, size_t *n, FILE *stream);
 char *Strdup(const char *str);

#endif
