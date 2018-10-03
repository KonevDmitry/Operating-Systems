#include <stdio.h>
#include <stdlib.h>

int main(){
	int num,*pointer;
	printf("Enter number of elements: ");
	scanf("%d",&num);
	pointer=(int *) calloc(num,sizeof(int));
	for(int i=0;i<num;i++)
		pointer[i]=i;
	for(int i=0;i<num;i++)
		printf("%d ",pointer[i]);
	free (pointer);
	return 0;
}
