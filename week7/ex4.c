#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define old_size 5
#define new_size 10
void* my_realloc(int *,int);
int main()
{
	    //checking for bigger size with garbage (checked for "garbage")
	    int*pointer;
	    pointer = (int*) calloc(old_size, sizeof(int));
	    for(int i=0;i<old_size;i++){
	        pointer[i]=i;
	    }
	    for(int i=0;i<old_size;i++)
	        printf("%d ",pointer[i]);
	    pointer = my_realloc(pointer,new_size*sizeof(int));
	    printf("\n");
	    for(int i=0;i<new_size;i++)
	        printf("%d ",pointer[i]);
	    return 0;
}
void* my_realloc(int *ptr,int another_size){
    if(ptr==NULL){
        return malloc(another_size * sizeof(int));
    }
    else if(another_size==0){
        free(ptr);
              return NULL;
    }
    else{
        int* new_ptr=malloc(another_size);
        if(new_ptr){
            memcpy(new_ptr,ptr,another_size);
            free(ptr);
        }
        return new_ptr;
    }
}

