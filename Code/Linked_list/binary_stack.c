#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node* PtrToNode;
typedef struct Node* Stack;
struct Node *top = NULL;

Stack CreateStack(){
    Stack S;
    S = malloc(sizeof(struct Node));
    if (S == NULL){
        printf("Out of space!!!\n");
    }
    S->next = NULL;
    return S;
}

void Push(Stack S, int x){
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL){
        printf("Out of space!!!\n");
    }
    else {
        TmpCell->data = x;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

int isEmpty(Stack S){
    return S->next == NULL;
}

int Pop(Stack S){
    PtrToNode FirstCell;
    int x;
    if (isEmpty(S)){
        printf("Empty stack\n");
        return 0;
    }
    else {
        FirstCell = S->next;
        x = FirstCell->data;
        S->next = S->next->next;
        free(FirstCell);
    }
    return x;
}

int Top(Stack S){
    if (!isEmpty(S)){
        return S->next->data;    
    }
    else {
        printf("Empty stack\n");
        return 0;
    }
}

void Binary(int N){
    Stack S;
    S = malloc(sizeof(struct Node));
    S -> next = NULL;
    while (N != 0){
        Push(S, N%2);
        N = N/2;
    }
    while(!isEmpty(S)){
        printf("%d", Pop(S));
    }
}

int main(){
    int N;
    printf("Enter a number: ");
    scanf("%d", &N);
    Binary(N);
    printf("\n");
    return 0;
}