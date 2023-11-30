#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root;

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

// AVL Tree Specific Functions. 
int NodeHeight(struct Node *r);
int BalanceFactor(struct Node *r);
struct Node *LL_Rotation(struct Node *r);
struct Node *LR_Rotation(struct Node *r);
struct Node *RR_Rotation(struct Node *r);
struct Node *RL_Rotation(struct Node *r);
struct Node* RInsert_in_AVL(struct Node *r, int x);  // Recursive Insert (In BST, there is iterative Insert)

int main(){

    root = NULL;
    // Insert elements into the AVL tree
    root = RInsert_in_AVL(root, 10);
    root = RInsert_in_AVL(root, 5);
    root = RInsert_in_AVL(root, 2);
    root = RInsert_in_AVL(root, 20);
    root = RInsert_in_AVL(root, 15);
    root = RInsert_in_AVL(root, 25);

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


// AVL Tree Functions:- 
int NodeHeight(struct Node *r){
    int hl;
    int hr;

    hl = r && r->lchild ? r->lchild->height : 0;
    hr = r && r->rchild ? r->rchild->height : 0;

    return hl > hr ? hl+1 : hr+1;
}
int BalanceFactor(struct Node *r){
    int hl;
    int hr;

    hl = r && r->lchild ? r->lchild->height : 0;
    hr = r && r->rchild ? r->rchild->height : 0;

    return hl-hr;
}

struct Node *LL_Rotation(struct Node *r){
    Node *rl = r->lchild;
    Node *rlr = rl->rchild;

    rl->rchild = r;
    r->lchild = rlr;
    r->height = NodeHeight(r);
    rl->height = NodeHeight(rl);

    if(root == r){
        root = rlr;
    }

    return rl;

}
struct Node *LR_Rotation(struct Node *r){
    struct Node *rl = r->lchild;
    struct Node *rlr = rl->rchild;

    rl->rchild = rlr->lchild;
    r->lchild = rlr->rchild;
    rlr->lchild = rl;
    rlr->rchild = r;

    rl->height = NodeHeight(rl);
    r->height = NodeHeight(r);
    rlr->height = NodeHeight(rlr);

    if(root == r){
        root = rlr;
    }

    return rlr;
}

struct Node *RR_Rotation(struct Node *r) {
    struct Node *rr = r->rchild;
    struct Node *rll = rr->lchild;

    r->rchild = rll;
    rr->lchild = r;

    r->height = NodeHeight(r);
    rr->height = NodeHeight(rr);

    if(root == rr){
        root = rr;
    }

    return rr;
}
struct Node *RL_Rotation(struct Node *r) {
    struct Node *rr = r->rchild;
    struct Node *rll = rr->lchild;

    rr->lchild = rll->rchild;
    r->rchild = rll->lchild;
    rll->rchild = rr;
    rll->lchild = r;

    r->height = NodeHeight(r);
    rr->height = NodeHeight(rr);
    rll->height = NodeHeight(rll);

    if(root == rll){
        root = rll;
    }

    return rll;
}

struct Node* RInsert_in_AVL(struct Node *r, int x){
    
    struct Node *temp = NULL;

    if(r == NULL){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = x;
        temp->height = 1;
        temp->lchild = temp->rchild = NULL;
        return temp;
    }
    if(x < r->data){
        r->lchild = RInsert_in_AVL(r->lchild, x);
    }
    else if(x > r->data){
        r->rchild = RInsert_in_AVL(r->rchild, x);
    }

    r->height = NodeHeight(r);

    // Check balance factor and perform rotations
    int balance = BalanceFactor(r);

    if (balance == 2) {
        // Left Heavy
        if (BalanceFactor(r->lchild) == 1 || BalanceFactor(r->lchild) == 0) {
            return LL_Rotation(r);
        } else if (BalanceFactor(r->lchild) == -1) {
            return LR_Rotation(r);
        }
    }
    else if (balance == -2) {
        // Right Heavy
        if (BalanceFactor(r->rchild) == -1 || BalanceFactor(r->rchild) == 0) {
            return RR_Rotation(r);
        } else if (BalanceFactor(r->rchild) == 1) {
            return RL_Rotation(r);
        }
    }
    return r;
}
