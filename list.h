#ifndef LIST_H
#define LIST_H

#include "memory_management.h"
#define true 1
#define false 0


typedef int bool;
typedef struct list_ List;


List * create_list(size_t content_size);//!< creates the list based on the content_size
void erase_list(List ** ptr);

void list_push_back(List* list,  void * item);
void list_push_front(List* list, void * item);



int list_size(List * list);
bool list_empty(List * list);

#endif
