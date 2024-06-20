#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};
typedef struct Node* Stack;
typedef struct Node* PtrToNode;

void Push(Stack S, char c){
    PtrToNode TmpCell;
    TmpCell = (struct Node*)malloc(sizeof(struct Node));
    if (TmpCell == NULL){
        printf("Out of space!!!");
    }
    else {
        TmpCell->data = c;
        TmpCell->next = S->next;
        S->next = TmpCell;
    }
}

int IsEmpty(Stack S){
    return S->next == NULL;
}

char Pop(Stack S){
    PtrToNode FirstCell = (struct Node*)malloc(sizeof(struct Node));
    char c;
    if (IsEmpty(S)){
        printf("Empty stack!!!");
    }
    else{
        FirstCell = S->next;
        c = FirstCell->data;
        S->next = S->next->next;
    }
    return c;
}

void Binary (int N){
    Stack S = malloc(sizeof(struct Node));
    S->next = NULL;

    while (N != 0){
        Push(S, N%2);
        N = N/2;
    }

    while (!IsEmpty(S)){
        printf("%d", Pop(S));
    }
}

int main(){
    Binary(7);
    return 0;
}