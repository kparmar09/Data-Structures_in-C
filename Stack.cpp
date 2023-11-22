#include <stdio.h> 
#include <stdlib.h> 


// For Creation of Stack Using Array
struct Stack{
    int size;
    int Top;
    int *A;
};
struct Stack* Create(int size){
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->Top = -1;
    s->size = size;
    s->A = (int *)malloc(s->size*sizeof(int));      
    return s; 
}
void push(struct Stack *s, int x){
    if((s)->Top == (s)->size-1){
        printf("Stack Overflow\n");
    }
    else{
        (s)->Top++;
        (s)->A[(s)->Top] = x;
    }
}
int pop(struct Stack *s){
    if((s)->Top < 0){
        printf("Stack Underflow");
    }
    else{
        int x = (s)->A[(s)->Top];
        (s)->Top--;
        return x;
    }
    return -1;
}
void Display(struct Stack *s){
    for(int i = s->Top; i >=0 ;i--){
        printf("%d ", s->A[i]);
    }
}


// For Creation of Stack Using Linked List
struct Node{
    int data;
    struct Node *next;
};
void pushLL(struct Node**t, int x){
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL){
        printf("Stack Overflow");
    }
    else{
        p->data = x;
        p->next = *t;
        *t = p;
    }
}
int popLL(struct Node **t){
    if(*t == NULL){
        return -1;
    }
    else{
        struct Node *p = *t;
        int x  = p->data;
        *t = (*t)->next;
        free(p);
        return x;
    }
}
void DisplayLL(struct Node *s){
while(s != NULL){
    printf("%d ", s->data);
    s = s->next;
}
}


int main(){

    /*
    struct Stack *s1;
    s1 = Create(5);
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    push(s1, 4);
    push(s1, 5);
    printf("%d \n", pop(s1));
    printf("%d \n", pop(s1));
    Display(s1);
    */

    /*
    struct Node *Top = NULL;
    pushLL(&Top, 1);
    pushLL(&Top, 2);
    pushLL(&Top, 3);
    pushLL(&Top, 4);
    pushLL(&Top, 5);
    printf("%d \n", popLL(&Top));
    DisplayLL(Top);
    */

}

