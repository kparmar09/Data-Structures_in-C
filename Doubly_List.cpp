#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

// Functions for Doubly Linked List:- (Correct Reverse Function..)
struct Node* Create(int A[], int size);
void Insert(struct Node **s, int x, int pos);
int Delete(struct Node **s, int pos);
void Reverse(struct Node **s);
void Display(struct Node *s);

//Functions for Circular Doubly Linked List:-
struct Node* CreateC(int A[], int size);
void InsertC(struct Node **s, int x, int pos);
int DeleteC(struct Node **s, int pos);
void DisplayC(struct Node *s);


int main(){
/*
    int A[10] = {1,2,3,4,5,6,7,8,9,0};
    struct Node *s = Create(A, 10);
    Insert(&s, 98, 5);
    Insert(&s, 99, 0);
    Display(s);
    Delete(&s, 3);
    Delete(&s, 1);
    Display(s);
*/
/*  
    int A[10] = {1,2,3,4,5,6,7,8,9,0};
    struct Node *s = CreateC(A, 10);
    InsertC(&s, 98, 5);
    InsertC(&s, 99, 0);
    DeleteC(&s, 5);
    DeleteC(&s, 1);
    DisplayC(s);
*/
}


// Functions for Doubly Linked List:- (Correct Reverse Function..)
struct Node* Create(int A[], int size){
    struct Node *s = (struct Node*)malloc(sizeof(struct Node));
    s->data = A[0];
    s->prev = NULL;
    s->next = NULL;
    struct Node *last = s;
    struct Node *t;
    for(int i = 1; i < size; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return s;
}
void Insert(struct Node **s, int x, int pos){
    struct Node *p = (*s);
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(pos == 0){
        t->data = x;
        t->next = (*s);
        t->prev = NULL;
        (*s)->prev = t;
        (*s) = (*s)->prev;
    }
    else{

        for(int i = 0; i < pos-1; i++){
            p = p->next;
        }
        t->data = x;
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
    }
}
int Delete(struct Node **s, int pos){
    struct Node *p = (*s);
    if(pos == 1){
        (*s) = (*s)->next;
        (*s)->prev = NULL;
        int x = p->data;
        free(p);
        return x;
    }
    else{
        for(int i = 0; i < pos-1; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        int x = p->data;
        free(p);
        return x;
    }
}
void Reverse(struct Node **s){
    struct Node *p = (*s);
    while(p != NULL){
        struct Node *t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;  // next and prev have been exchanged so to move ahead we use p = p->prev. ***
        
        if(p->prev == NULL){
            (*s) = p;
        }
    }
}
void Display(struct Node *s){
    while(s != NULL){
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}

//Functions for Circular Doubly Linked List:-
struct Node* CreateC(int A[], int size){
    struct Node *s = (struct Node*)malloc(sizeof(struct Node));
    s->data = A[0];
    s->prev = NULL;
    s->next = NULL;
    struct Node *last = s;
    struct Node *t;
    for(int i = 1; i < size; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
    last->next = s;
    s->prev = last;
    return s;
}
void InsertC(struct Node **s, int x, int pos){
    struct Node *p = (*s);
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(pos == 0){
        t->data = x;
        t->prev = (*s)->prev;
        t->next = (*s);
        (*s)->prev->next = t;
        (*s)->prev = t;
        (*s) = t;
    }
    else{
        for(int i = 0; i < pos-1; i++){
            p = p->next;
        }
        t->data = x;
        t->prev = p;
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
    }
}
int DeleteC(struct Node **s, int pos){
    struct Node *p = (*s);
    if(pos == 1){
        (*s)->prev->next = (*s)->next;
        (*s)->next->prev = (*s)->prev;
        (*s) = p->next;
        int x = p->data;
        free(p);
        return x;
    }
    else{
        for(int i = 0; i < pos-1; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        int x = p->data;
        free(p);
        return x;
    }
}
void DisplayC(struct Node *s){
    struct Node *p = s;
    do{
        printf("%d ", p->data);
        p = p->next;
    }while(p != s);
    printf("\n");
}
