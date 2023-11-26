#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
int data;
struct Node *next;
};

// Functions for Singly Linked List:-
void Create(struct Node **s, int A[], int size);
void Display(struct Node *s);
int Count(struct Node *s);
int Sum(struct Node *s);
int Min(struct Node *s);
int Max(struct Node *s);
int Search(struct Node **s, int key);
void Insert(struct Node **s, int x, int pos);
int Delete(struct Node **s, int pos);
void Reverse(struct Node **s);
void concatenate(struct Node *s, struct Node *t);
int checkLoop(struct Node *s);

// Sorted Linked List Functions:-
int isSorted(struct Node *s);
void sInsert(struct Node **s, int x);
struct Node* Merge(struct Node *x, struct Node *y);
void removeDuplicate(struct Node *s);

// Functions for Circular Singly Linked List:- 
struct Node* CreateC(int A[], int size);
void InsertC(struct Node **s, int x, int pos);
int DeleteC(struct Node **s, int pos);


int main(){
    // TO DO : Fix Delete Function and removeDuplicate function.....
    // Fix DeleteC function too
    // Here Indexing is not same as Array... We are strictly starting from 1. (Not as important as it seems)
}


// Functions for Singly Linked List:-
void Create(struct Node **s, int A[], int size){
*s = (struct Node*)malloc(sizeof(struct Node));
(*s)->data = A[0];
(*s)->next = NULL;

struct Node *last = *s;
struct Node *t;

for(int i = 1; i < size; i++){
t = (struct Node*)malloc(sizeof(struct Node));
t->data = A[i];
t->next = NULL;
last->next = t;
last = t;
}
}
void Display(struct Node *s){
while(s != NULL){
    printf("%d ", s->data);
    s = s->next;
}
}
int Count(struct Node *s){
    int x = 0;
    while(s != NULL){
        x++;
        s = s->next;
    }
    return x;
}
int Sum(struct Node *s){
    int x = 0;
    while(s != NULL){
        x = x + s->data;
        s = s->next;
    }
    return x;
}
int Min(struct Node *s){
    int x = INT_MAX;
    while(s != NULL){
        if(s->data < x){
            x = s->data;
        }
        s = s->next;
    }
    return x;
}
int Max(struct Node *s){
    int x = INT_MIN;
    while(s != NULL){
        if(s->data > x){
            x = s->data;
        }
        s = s->next;
    }
    return x;
}

int Search(struct Node **s, int key){
    struct Node *p = *s;
    struct Node *q = NULL;

    while(p != NULL){
        if(p->data == key){
            q->next = p->next;
            p->next = *s;
            (*s) = p;
            return 1;
        }
        q = p;
        p = p->next;
    }
    return 0;
}
void Insert(struct Node **s, int x, int pos){
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    struct Node *p = *s;
    if(pos == 0){   // Pos = 0 defines before Pos 1 and Pos = 1 defines after Pos 1.... Pos = 0 inserts before P1 and Pos = 1 inserts after P1. 
        t->next = *s;
        (*s) = t;
    }
    else{
        for(int i = 0; i < pos-1; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
int Delete(struct Node **s, int pos){
    struct Node *p = *s;
    struct Node *q = NULL;
    int x;

    if(pos == 1){
        x = p->data;
        free(*s);
        *s = p->next;
        return x;
    }

    for(int i = 0; i < pos - 1; i++){
        q = p;
        p = p->next;
    }

    q->next = p->next;
    x = p->data;
    free(p);
    return x;
}
void Reverse(struct Node **s){
    struct Node *p = *s;
    struct Node *q = NULL;
    struct Node *r = NULL;

    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    (*s) = q; // Making first point to the first element of reversed linked list
}
void concatenate(struct Node *s, struct Node *t){
    struct Node *p = s;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = t;
}
int checkLoop(struct Node *s){
    struct Node *p = s;
    struct Node *q = s;
    do{
        q = q->next;
        p = p->next;
        p = p!=NULL?p->next:NULL;
    }while(p && q && p!=q);
    
    if(p == q){
        return 1;
    }
    return 0;
}

// All the Functions for Sorted Linked List:-
int isSorted(struct Node *s){
    struct Node *p = s;
    int x = INT_MIN;
    while(p != NULL){
        if(x > p->data){
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}
void sInsert(struct Node **s, int x){
    struct Node *p = *s;
    struct Node *q = NULL;
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    while(p != NULL && x > p->data){
        q = p;
        p = p->next;
    }
    if(q == NULL){       // For the case where we insert the smallest element in sorted L.L ie. first pos.
        t->next  = *s;
        *s = t;
    }
    else{
    t->next = q->next;
    q->next = t;
    }
}
struct Node* Merge(struct Node *x, struct Node *y){
    struct Node *p = x;
    struct Node *q = y;
    struct Node *third = NULL;
    struct Node *last = NULL;

    if(p->data < q->data){
        third  = last = p;
        p = p->next;
    }
    else{
        third = last = q;
        q = q->next;
    }

    while(p != NULL && q != NULL){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
        }
    }
    if(p != NULL){
        last->next = p;
    }
    else if(q != NULL){
        last->next = q;
    }
    return third;
}
void removeDuplicate(struct Node *s){
    struct Node *q = s;
    struct Node *p = s->next;
    while(p != NULL){
        if(p->data = q->data){
            q->next = p->next;
            free(p);
            p = q->next;
        }
        else{
            q = p;
            p = p->next;
        }
    }
}

// Functions for Circular Singly Linked List:- 
struct Node* CreateC(int A[], int size){
    struct Node *s = (struct Node*)malloc(sizeof(struct Node));
    (s)->data = A[0];
    (s)->next = NULL;
    struct Node *last = (s);
    struct Node *t;
    int i;
    for(i = 1; i < size; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    last->next = (s);
    return s;
}
void DisplayC(struct Node *s){
    struct Node *p = s;
    do{
        printf("%d", p->data);
        p = p->next;
    }while(s != p);
    printf("\n");
}
void InsertC(struct Node **s, int x, int pos){
    struct Node *p = *s;
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    if(pos == 0){
        do{
            p = p->next;
        }while(p->next != (*s));
        t->data = x;
        t->next = p->next;
        p->next = t;
        (*s) = t;
    }
    else{
        for(int i = 0; i < pos - 1; i++){
            p = p->next;
        }
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
int DeleteC(struct Node **s, int pos){
    struct Node *p = (*s);
    struct Node *q = NULL;
    if(pos == 1){
        int x = p->data;
        (*s) = (*s)->next;
        free(p);
        return x;
    }
    else{
        for(int i = 0; i < pos - 1; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        int x = p->data;
        free(p);
        return x;
    }
}