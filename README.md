# Stack Implementation in C

This project is a simple implementation of a stack data structure in C using an array. It provides basic stack operations like push (insert), pop (remove), and display.

## Table of Contents

- [General Info](#general-info)
- [Technologies](#technologies)
- [Setup](#setup)
- [Usage](#usage)

## General Info

This section provides an overview of some concepts used in this project.

### LIFO and FIFO

- **LIFO (Last In, First Out)**: This is the characteristic property of a stack. The last element inserted is the first one to be removed.

- **FIFO (First In, First Out)**: This is the characteristic property of a queue. The first element inserted is the first one to be removed.

### Stack and Queue

- **Stack**: A stack is a linear data structure that follows the LIFO order. Stacks are useful in situations where we need to reverse a set of items, match parentheses/brackets in compiler syntax checking, or in algorithms like depth-first search.

- **Queue**: A queue is a linear data structure that follows the FIFO order. Queues are useful in scenarios like handling requests on a single shared resource like a printer, thread scheduling in operating systems, or in algorithms like breadth-first search.

### Common Implementations

- **Stacks** are commonly implemented using arrays (as in this project), linked lists, or even other data structures like queues.

- **Queues** are often implemented using arrays or linked lists. There are also specialized types of queues like priority queues and dequeues.

### Common Use Cases

- **Stacks**: Used in parsing, expression evaluation, depth-first search in graph algorithms, undo functionality in editors, and so on.

- **Queues**: Used in handling requests on a shared resource (like a printer), thread scheduling, and breadth-first search in graph algorithms.

### Global Variables

In this project, we use global variables to hold the stack array, the top index, and the user's choice of operation. Global variables are variables that are declared outside of all function blocks, which makes them accessible to all functions. However, extensive use of global variables can make a program hard to understand and debug, so use them sparingly.

## Technologies

Project is created with:

- C programming language

## Setup

To run this project, you need a C compiler like GCC. Compile the file with the following command:

```bash
gcc stack.c -o stack
```

Then run the program with:

```bash
./stack
```

## Usage

When you run the program, you will see a menu of operations:

1. Insert
2. Delete
3. Display
4. Exit

Enter your choice according to the operation you want to perform. The program will then either perform the operation or prompt you for more input as necessary.

Please note that this is a simple implementation meant for educational purposes, and it may not handle all possible edge cases or errors.
