#ifndef C_UTILS
#define C_UTILS
#define INTEGER sizeof(int)
#define casting (void*)&

#include "list.h"


void printInt(void *n){
	printf("%d",*(int *)n);
}
#endif
