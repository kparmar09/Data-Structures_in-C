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

int main(){

    struct Node *root = createTree();
    DisplayTree(root);
    
}

