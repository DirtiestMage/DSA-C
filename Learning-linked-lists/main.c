// 1.Define a linked list
// 2.Add push and pop functions for it
// 3.Print values for linked list by traversing through it
// 4.Add item to beginning of linked list

#include<stdio.h>
#include<stdlib.h>


typedef struct node {

    int val;
    struct node * next;

} node_t;

void push(node_t * head, int value){

    node_t * current = head; 
    while(current->next!=NULL){
        current = current->next;
    }

    current->next = (node_t*)malloc(sizeof(node_t));
    current->next->val = value;
    current->next->next= NULL;

}

void pushbottom(node_t ** head, int value){

    node_t * newnode = NULL;
    newnode = (node_t*) malloc(sizeof(node_t));
    newnode->val = value;
    newnode->next = *head;
    *head = newnode;

}

int pop(node_t * head){

    int poppedvalue;
    node_t * current = head;
    if (current==NULL){
        printf("Empty list!");
        return 0;
    }
    while(current->next->next !=NULL){
        current = current->next;
    }
    poppedvalue = current->next->val;
    free(current->next);
    current->next = NULL;
    return poppedvalue;

}

void print_list(node_t * head) {

    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }

}


int main(){

    node_t * head = NULL;
    head = (node_t*)malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->next = NULL;
    head->val = 1;


    int n;
    scanf("%d",&n);

    int p;
    scanf("%d",&p);
    head->val = p;

    while(n>1){
        
        scanf("%d",&p);
        push(head, p);
        n--;
    }
    pushbottom(&head, 25);
    print_list(head);

    return 0;
}