#ifndef MONTY_H
#define MONTY_H

/* Includes */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* #MACROS */

#define DEBUG(M) printf("%s%s:%d\n", M, __FILE__, __LINE__);
#define DBG printf("%s:%d\n", __FILE__, __LINE__)
#define FreeVar(var) do { \
    if (var) { \
        free(var); \
       var = NULL; \
    } \
} while(0)

#define FREE_2D_ARR(arr) { \
    if (arr) { \
       Free_2D_Array(arr); \
        arr = NULL; \
    } \
} while(0)

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
typedef struct stack_s {
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
typedef struct instruction_s {
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*""" Global Variables"""*/

// extern char *Command;

/*""" Functions Prototype """"*/

/* memory.c*/
size_t Free_2D_Array(char **Array);

/* Get_Input.c*/
size_t Get_Inout(char *filePath);



/*String*/
char  **Tokenize_in_Arr(char *string, char*  delim);
size_t Print_2D_Arr(char** array, size_t isNull);


#endif
