#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
int data;
struct Node *next;
};

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

int main(){

    // TO DO : Fix Delete Function and removeDuplicate function.....
    // Fix DeleteC function too


/*

int A[5] = {1,2,3,4,5};
int B[5] = {6,7,8,9,10};
struct Node *first;
struct Node *second;
Create(&first, A, 5);
Create(&second, B, 5);

//Display(first);

printf("\nThe count of nodes in the Linked List is: %d\n", Count(first));
printf("The Sum of all elements in the Linked List is: %d\n", Sum(first));
printf("The Minimum Element in the Linked List is: %d\n", Min(first));
printf("The Maximum Element in the Linked List is: %d\n", Max(first));

//int x = Search(&first, 2);
//if(x == 1){printf("Key Found!\n");}
//else{printf("Key Not Found!\n");}
//Display(first);

//Insert(&first, 3, 1); // Inserts 3 after Pos 1.
//Display(first);
//printf("\nFirst points to data -> %d\n", first->data);
//int y = Delete(&first, 2);                                   // Error : Endless Loop when deleting Pos 1 ie. Pos at which front points.
//printf("The Deleted element is: %d\n", y);
//Display(first);

//Reverse(&first);
//Display(first);
//printf("\n");

//concatenate(first, second);
//Display(first);

// Deliberately creating a loop in second:-  (Consequence is that a loop will also be created in first as first and second are concatenated in earlier command)
struct Node *p = second;
for(int i = 0; i < 3; i++){
    p = p->next;
}
p->next = second;

Display(first);
int z = checkLoop(second);
printf("\nResult of checkLoop function is: %d", z);


int S1[5] = {2,4,6,8,10};
int S2[7] = {1,3,7,9,11,11,11};
struct Node *sorted1;
struct Node *sorted2;
Create(&sorted1, S1, 5);
Create(&sorted2, S2, 7);

//printf("Result of isSorted function for [sorted1] L.L.: %d\n",isSorted(sorted1));
//sInsert(&sorted1, 1);
//Display(sorted1);

struct Node *third = Merge(sorted1, sorted2);
Display(third);
printf("\n");

printf("First pointer points at -> %d\n", sorted1->data);
printf("Second pointer points at -> %d\n", sorted2->data);
printf("Third pointer points at -> %d\n", third->data);


Display(sorted2);
removeDuplicate(sorted2);


int A[10] = {1,2,3,4,5,6,7,8,9,0};
struct Node *c = CreateC(A, 10);

InsertC(&c, 20, 3);
DisplayC(c);
printf("%d\n",DeleteC(&c, 1));
DisplayC(c);

*/
}

// Here Indexing is not same as Array... We are strictly starting from 1.