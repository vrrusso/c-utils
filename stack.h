#ifndef STACK_H
#define STACK_H

#include "memory_management.h"
#define true 1
#define false 0

typedef int bool;
typedef struct stack_ Stack;

Stack * create_stack(size_t content_size);//!< create the stack based on the content size
void erase_stack(Stack ** ptr);


//!< ***always*** use item as a var in the client program
bool stack_push(Stack * stack, void * item);

void * stack_top(Stack * stack);///TODO coment this shit tho


void  stack_pop(Stack * stack);



void stack_print(Stack * stack, void (*printer_function)(void *));

int stack_size(Stack * stack);
bool stack_empty(Stack * stack);

#endif
