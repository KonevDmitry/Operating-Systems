#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter number of elements:\n");
    char str[5];
    gets(str);
    int num;
    sscanf(str, "%d", &num);
    int arr[num];
    printf("Elements:\n");
    for(int i=0;i<num;i++)
        scanf("%d",&arr[i]);
    bubble_sort(arr, num);
    printf("Sorted: \n");
    for(int i=0;i<num;i++)
        printf("%d ",arr[i]);
    return 0;
}
void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}
void bubble_sort(int arr[], int n){
   for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
