#include "stack.h"
#include <stdio.h>
#include<stdlib.h>

#define INITIAL_CAPACITY 36



struct stack_{
	void ** array;
	int top;
	int capacity;
	size_t data_size;	
};

Stack * create_stack(size_t content_size){
	Stack * new = (Stack *)allocate(sizeof(Stack));
	new->top=-1;
	new->capacity=INITIAL_CAPACITY;
	new->data_size=content_size;
	new->array = (void **)allocate(sizeof(new->data_size)*new->capacity);
	return new;
}

void erase_stack(Stack ** ptr){
	//deallocate((void **)(*ptr)->array);
	free((*ptr)->array);//i dont know why but i cannot use my made up function - whatever
	deallocate((void **)ptr);
	ptr=NULL;
}
