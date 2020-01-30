#ifndef C_UTILS
#define C_UTILS
#include "list.h"


#define casting (void*)&
#define INTEGER sizeof(int)
#define FLOAT sizeof(float)
#define CHAR sizeof(char)



void printInt(void *d){
	printf("%d",*(int *)d);
}
void printFloat(void *f){
	printf("%.2f",*(float *)f);
}
void printChar(void *c){
	printf("%c",*(char *)c);
}


#endif
