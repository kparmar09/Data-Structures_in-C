#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *A;
};

// Simple Queue Functions:-
struct Queue* CreateQueue(int size){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->A = (int*)malloc(q->size*sizeof(struct Queue));
    return q;
}
void enqueue(struct Queue *q, int x){
    if(q->rear == q->size-1){
        printf("Queue Full\n");
    }
    else{
        q->rear++;
        q->A[q->rear] = x;
    }
}
int dequeue(struct Queue *q){
    if(q->front == q->rear){
        printf("Queue Empty\n");
        return -1;
    }
    else{
        q->front++;
        int x = q->A[q->front];
        return x;
    }
}
void display(struct Queue *q){
    for(int i = q->front+1; i <= q->rear; i++){
        printf("%d ", q->A[i]);
    }
    printf("\n");
}

int isEmpty(struct Queue *q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}
int isFull(struct Queue *q){
    if(q->rear == q->size-1){
        return -1;
    }
    return 0;
}

int first(struct Queue *q){
    return q->A[q->front+1];
}
int last1(struct Queue *q){
    return q->A[q->rear];
}


// Circular Queue Functions:- (NOT WORKING PROPERLY)

void Cenqueue(struct Queue *q, int x){
    if((q->rear+1)%q->size == q->front){
        printf("Queue Full\n");
    }
    else{
        q->rear = (q->rear + 1)%q->size;
        q->A[q->rear] = x;
    }
}

void Cdisplay(struct Queue *q){
    for(int i = q->front+1; i < q->size; i = (i+1)%q->size){
        printf("%d ", q->A[i]);
    }
    printf("\n");
}




int main(){

    /*
    struct Queue *Q;
    Q = CreateQueue(5);
    enqueue(Q, 1);
    enqueue(Q, 2);
    enqueue(Q, 3);
    enqueue(Q, 4);
    enqueue(Q, 5);
    dequeue(Q);
    Display(Q);
    printf("%d\n", first(Q));
    printf("%d\n", last(Q));
    */

    /*
    struct Queue *Q;
    Q = CreateQueue(5);
    Cenqueue(Q, 1);
    Cenqueue(Q, 2);
    Cenqueue(Q, 3);
    Cenqueue(Q, 4);
    Cenqueue(Q, 5);
    //Cenqueue(Q, 6);
    //Cdequeue(Q);
    //Cdequeue(Q);
    //Cenqueue(Q, 6);
    Cdisplay(Q);
    */

}