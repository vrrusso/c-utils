#ifndef LIST_H
#define LIST_H

#include "memory_management.h"
#define true 1
#define false 0


typedef int bool;
typedef struct list_ List;


List * create_list(size_t content_size);//!< creates the list based on the content_size
void erase_list(List ** ptr);

//!<  ***alwayss*** use item as a var in the client program
bool list_push_back(List* list,  void * item);
bool list_push_front(List* list, void * item);

void * list_front(List * list);
void * list_back(List * list);

void list_pop_front(List * list);
void list_pop_back(List * list);


//!< uses you own print function based on data type
void list_print(List* list, void (*printer_function)(void *) );
void list_reverse_print(List* list,void (*printer_function)(void *));

int list_size(List * list);
bool list_empty(List * list);

#endif
