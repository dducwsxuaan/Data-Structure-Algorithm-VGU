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
    Stack S = malloc(sizeof(struct Node));
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

int main(){
    Stack S = CreateStack();
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    printf("%d\n", Pop(S));
    printf("%d\n", Pop(S));
    printf("%d\n", Pop(S));
    printf("%d\n", Pop(S));
    return 0;
}