#include "list.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct node_{
	void * content;
	struct node_ * next;
}Node;

struct list_{
	Node * begin;
	Node * end;
	int size;
	size_t data_size;
};

List * create_list(size_t content_size){
	List * new = (List*)allocate(sizeof(List));
	new->begin=NULL;
	new->end=NULL;
	new->size=0;
	new->data_size=content_size;
	return new;
}

void erase_nodes(Node * begin){
	Node * aux=begin;
	while(begin !=NULL){
		begin=begin->next;
		deallocate((void*)&(aux->content));
		deallocate((void*)&aux);
		aux=begin;
	}
}

void erase_list(List ** ptr){
	erase_nodes((*ptr)->begin);
	deallocate((void *)ptr);
}

bool list_empty(List * list){
	if(list!=NULL)
		return list->size==0?true:false;
	return true;
}

Node * allocate_node(void * item, size_t data_size){
	Node * new = (Node *)allocate(sizeof(Node));
	new->content = allocate(data_size);
	//transfer the data from item to new->content byte to byte
	//TODO entender essa merda melhor
	int i;
    for (i=0; i<data_size; i++){
       	*(char *)(new->content + i) = *(char *)(item + i);	
	}
	return new;
}

bool list_push_back(List * list,void * item){
	if(list!=NULL){
		Node * new = allocate_node(item,list->data_size);	
		if(!list_empty(list))
			list->end->next = new;
		else
			list->begin = new;
		new->next=NULL;
		list->end = new;
		list->size++;
		return true;
	}
	return false;
}

void * list_front(List * list){
	if(list != NULL && !list_empty(list))
		return list->begin->content;
	return NULL;
}

void * list_back(List * list){
	if(list != NULL && !list_empty(list))
		return list->end->content;
	return NULL;
}


bool list_push_front(List * list, void * item){
	if(list!=NULL){
		Node * new = allocate_node(item,list->data_size);
		if(!list_empty(list))
			new->next = list->begin;
		else{
			list->end=new;		
			new->next=NULL;
		}
		list->begin = new;
		list->size++;
		return true;
	}
	return false;
}

void list_print(List* list, void (*printer_function)(void *)){
	if(list != NULL && !list_empty(list)){
		Node * aux = list->begin;
		while(aux != NULL){
			(*printer_function)(aux->content);
			aux=aux->next;
		}
		printf("\n");
		return;
	}
	printf("Non initialized or empty listy!");
}




