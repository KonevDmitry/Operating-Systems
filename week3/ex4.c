#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Enter number of elements:\n");
    char str[5];
    gets(str);
    int count;
    sscanf(str, "%d", &count);
    int numbers[count];
    printf("Elements:\n");
    for(int i=0;i<count;i++)
      scanf("%d",&numbers[i]);
   quicksort(count,numbers,0,count-1);
   printf("Sorted:\n");
   for(int i=0;i<count;i++)
      printf("%d ",numbers[i]);
    return 0;
}
void quicksort(int arr_size,int arr[arr_size],int first,int last){
   int i, j, pivot, tmp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(i<last && arr[i]<=arr[pivot])
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j)
            swap(&arr[i], &arr[j]);
      }
      tmp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=tmp;
      quicksort(arr_size,arr,first,j-1);
      quicksort(arr_size,arr,j+1,last);
   }
}
void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}
