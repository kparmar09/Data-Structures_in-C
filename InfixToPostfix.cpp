#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int Top;
    char *A;
};

struct Stack* Create(int size){
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->Top = -1;
    s->size = size;
    s->A = (char*)malloc(s->size*sizeof(char));
    return s;
}
void push(struct Stack *s, char x){
    if(s->Top == s->size - 1){
        printf("Stack Overflow");
    }
    else{
        s->Top++;
        s->A[s->Top] = x;
    }
}
char pop(struct Stack *s){
    if(s->Top == -1){
        return -1;
    }
    else{
        int x = s->A[s->Top];
        s->Top--;
        return x;
    }
}
char stackTop(struct Stack *s){
    if(s->Top == -1){
        return -1;
    }
    else{
        return s->A[s->Top];
    }
}

int pre(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    else if(x == '*' || x == '/'){
        return 2;
    }
    else if(x == '#'){
        return -1;
    }
    return 0;
}
int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '#'){
        return 0;
    }
    return 1;
}
char* InfixToPostfix(char infix[]){
    char *postfix = (char*)malloc(20*sizeof(char));
    struct Stack *s = Create(20);
    push(s, '#');

    int i = 0, j = 0;

    while(infix[i] != '\0'){

        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(pre(infix[i]) > pre(stackTop(s))){
                push(s, infix[i++]);
            }
            else{
                postfix[j++] = pop(s);
            }
        }
    }

    while(s->Top != -1){
        postfix[j++] = pop(s);
    }

    postfix[j] = '\0';
    return postfix;
}
int PostfixEval(char *pf){
    struct Stack *s = Create(20);
    int i = 0;
    int x1, x2, r;

    while(pf[i] != '#'){
        if(isOperand(pf[i])){
            push(s, pf[i++] - '0');  // Converting character's ASCII code into the actual Integer.
        }
        else{
            x2 = pop(s);
            x1 = pop(s);
            switch(pf[i]){
                case '+': r = x1 + x2;
                push(s, r);
                break;
                case '-': r = x1 - x2;
                push(s, r);
                break;
                case '*': r = x1 * x2;
                push(s, r);
                break;
                case '/': r = x1 / x2;
                push(s, r);
                break;
            }
            i++;
        }
    }
    return pop(s);
}

// Still this only works for expressions without parenthesis and without operators having right to left precendence
// Work in Progress...
// Will need to add functionality for parenthesis checking and other requirements for Postfix conversion
// The evaluation will only work for single digit numbers as converting double digit numbers which are characters into int is a challenge..
int main(){

    char infix[20];
    scanf("%s", infix);
    char *pf;
    pf = InfixToPostfix(infix);
    
    printf("The Postfix Expression is:- ");
    for(int i = 0; pf[i] != '\0'; i++){
        printf("%c", pf[i]);
    }
    printf("\nThe evaluation of the postfix expression yields: %d", PostfixEval(pf));

}

/*
eg: INFIX: 1+2*3-4/2
POSTFIX: 123*+42/-# (Ignore # as it's just to get the function started as there needs to be a stackTop element initially)
postfix evaluation: 5   
*/