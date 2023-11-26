#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue{
    int size;
    int front;
    int rear;
    struct Node **A;
};

// Simple Queue for storing Tree Node addresses. (Required for tree implementation)
struct Queue* CreateQueue(int size);
void enqueue(struct Queue *q, struct Node *s);
struct Node* dequeue(struct Queue *q);
int isEmpty(struct Queue *q);

// Binary Trees implementation and required Functions.
struct Node* createTree();
void PreOrder(struct Node *r);
void InOrder(struct Node *r);
void PostOrder(struct Node *r);
int Height(struct Node *r);
int Count(struct Node *r);
void DisplayTree(struct Node *r);

// Specific Functions for Binary Search Trees (BST):-
struct Node* Search_in_BST(struct Node *r, int key);
void Insert_in_BST(struct Node *r, int x);
struct Node* InOrder_Predecessor(struct Node *p);
struct Node* InOrder_Successor(struct Node *p);
struct Node* Delete_from_BST(struct Node **r, int x);

// NOTE: While inputting values into BST, always follow the BST principle and don't add duplicates.
int main(){
    struct Node *root = createTree();
    struct Node *x;
    x = Search_in_BST(root, 3);
    x!=NULL?printf("Key Found!\n"):printf("Key Not Found!\n");
    Insert_in_BST(root, 2);
    Insert_in_BST(root, 60);
    Delete_from_BST(&root, 70);
    //Delete_from_BST(&root, 50);
    //Check Later .. Might be a problem while deleting Root value.
    DisplayTree(root);
    return 0;
}

// Queue Functions:-
struct Queue* CreateQueue(int size){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->A = (struct Node**)malloc(q->size*sizeof(struct Node*));
    return q;
}
void enqueue(struct Queue *q, struct Node *s){
    if(q->rear == q->size-1){
        printf("OverFlow\n");
    }
    else{
        q->rear++;
        q->A[q->rear] = s;
    }
}
struct Node* dequeue(struct Queue *q){
    struct Node *t = NULL;
    if(q->front == q->rear+1){
        printf("UnderFlow\n");
        return t;
    }
    else{
        q->front++;
        t = q->A[q->front];
        return t;
    }
}
int isEmpty(struct Queue *q){
    if(q->front >= q->rear || (q->front == -1 && q->rear == -1)){
        return 1;
    }
    return 0;
}

// Binary Tree Functions:-
struct Node* createTree(){
    struct Queue *q = CreateQueue(100);
    struct Node *r = (struct Node*)malloc(sizeof(struct Node));
    int x;
    printf("Enter the Root Data: ");
    scanf("%d", &x);
    r->lchild = r->rchild = NULL;
    r->data = x;
    enqueue(q, r);

    while(!isEmpty(q)){
        struct Node *p = dequeue(q);

        printf("Enter left child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1){
            struct Node *t = (struct Node*)malloc(sizeof(struct Node));
            t->lchild = t->rchild = NULL;
            t->data = x;
            p->lchild = t;
            enqueue(q, t);
        }

        printf("Enter right child of %d: ", p->data);
        scanf("%d", &x);
        if(x != -1){
            struct Node *t = (struct Node*)malloc(sizeof(struct Node));
            t->lchild = t->rchild = NULL;
            t->data = x;
            p->rchild = t;
            enqueue(q, t);
        }

    }
    return r;
}

void PreOrder(struct Node *r){
    if(r){
        printf("%d ", r->data);
        PreOrder(r->lchild);
        PreOrder(r->rchild);
    }
}
void InOrder(struct Node *r){
    if(r){
        InOrder(r->lchild);
        printf("%d ", r->data);
        InOrder(r->rchild);
    }
}
void PostOrder(struct Node *r){
    if(r){
        PostOrder(r->lchild);
        PostOrder(r->rchild);
        printf("%d ", r->data);
    }
}

int Height(struct Node *r){
    int x = 0, y = 0;
    if(r == NULL){
        return 0;
    }
    x = Height(r->lchild);
    y = Height(r->rchild);
    return x>y?x+1:y+1;
}
int Count(struct Node *r){
    int x, y;
    if(r){
        x = Count(r->lchild);
        y = Count(r->rchild);
        return x+y+1;
    }
    else{
        return 0;
    }
}
void DisplayTree(struct Node *r){
    printf("PreOrder Traversal: ");PreOrder(r);printf("\n");
    printf("InOrder Traversal: ");InOrder(r);printf("\n");
    printf("PostOrder Traversal: ");PostOrder(r);printf("\n");
    printf("Count of Nodes in the Tree is: %d\n", Count(r));
    printf("Height of the Tree is: %d\n", Height(r));
}

// BST Specific Functions:-
struct Node* Search_in_BST(struct Node *r, int key){
    while(r){
        if(r->data == key){
            return r;
        }
        else if(key < r->data){
            r = r->lchild;
        }
        else{
            r = r->rchild;
        }
    }
    return NULL;
}

void Insert_in_BST(struct Node *r, int x){
    struct Node *p = r;
    struct Node *q = NULL;

    while(p != NULL){
        q = p;
        if(p->data == x){
            printf("No Duplicates in BST..");
            return;
        }
        else if(x < p->data){
            p = p->lchild;
        }
        else{
            p = p->rchild;
        }
    }

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->lchild = temp->rchild = NULL;

    if(temp->data < q->data){
        q->lchild = temp;
    }
    else{
        q->rchild = temp;
    }
    
}

struct Node *InOrder_Predecessor(struct Node *p){
    while(p && p->rchild != NULL){
        p = p->rchild;
    }
    return p;
}
struct Node *InOrder_Successor(struct Node *p){
    while(p && p->lchild != NULL){
        p = p->lchild;
    }
    return p;
}

struct Node* Delete_from_BST(struct Node **r, int x){
    struct Node *p = (*r);
    if(p == NULL){
        return NULL;
    }
    if(p->lchild == NULL && p->rchild == NULL){
        if(p == (*r)){
            (*r) = NULL;
        }
        free(p);
        return NULL;
    }

    if(x < p->data){
        p = Delete_from_BST(&p->lchild, x);
    }
    else if(x > p->data){
        p = Delete_from_BST(&p->rchild, x);
    }
    else{
        if(Height(p->lchild) > Height(p->rchild)){
            struct Node *q = InOrder_Predecessor(p->lchild);
            p->data = q->data;
            p->lchild = Delete_from_BST(&p->lchild, q->data);
        }
        else{
            struct Node *q = InOrder_Successor(p->rchild);
            p->data = q->data;
            p->lchild = Delete_from_BST(&p->rchild, q->data);
        }
    }
    return p;
}