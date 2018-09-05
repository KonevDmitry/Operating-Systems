#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
int main(){
     struct Node* head  = NULL;
    //push added just because we need to insert number after another
    //small tests
    push(&head, 1);
    insert_node(head, 8);
    print_list(head);
    printf("\n");
    push(&head, -3);
    insert_node(head->next, 123);
    print_list(head);
    printf("\n");
    delete_node(&head,1);
    print_list(head);
    return 0;
}
void push(struct Node** head, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->next = (*head);
    new_node->prev =NULL;
    *head = new_node;
    new_node->data  = new_data;
    if ((*head) != NULL)
        (*head)->prev = new_node;
    (*head) = new_node;
}
void insert_node(struct Node* previous, int new_data){
    if (previous == NULL) {
        printf("Can't be inserted after NULL or there is no entered number");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = previous->next;
    previous->next = new_node;
    new_node->prev = previous;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}
void delete_node(struct Node **head, int key){
    struct Node* tmp = *head, *previous;
     if (tmp != NULL && tmp->data == key){
        *head = tmp->next;
        previous=tmp->prev;
        free(tmp);
        return;
    }
    while (tmp != NULL && tmp->data != key){
        previous = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    previous->next = tmp->next;
    free(tmp);
}
void print_list(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
