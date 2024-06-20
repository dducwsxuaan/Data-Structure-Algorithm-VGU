#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node* PtrToNode;
typedef struct Node* Stack;
struct Queue {
    PtrToNode Head;
    PtrToNode Tail;
};
typedef struct Queue *Queue;

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

Queue CreateQueue(){
    Queue Q = malloc(sizeof(struct Queue));
    Q->Head = malloc(sizeof(struct Node));
    Q->Head->next = NULL;
    Q->Tail = Q->Head;
    return Q;
}

void Enqueue(Queue Q, int x){
    PtrToNode TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL){
        printf("Out of space!!!");
    }
    else{
        TmpCell->data = x;
        TmpCell->next = Q->Tail->next;
        Q->Tail->next = TmpCell;
        Q->Tail = TmpCell;
    }
}

int IsEmpty(Queue Q){
    return Q->Head->next == NULL;
}

int top_Queue(Queue Q){
    if (IsEmpty(Q)){
        printf("Empty queue\n");
        return -1;
    }
    return Q->Head->next->data;
}
// Dequeue is similar to pop
int Dequeue(Queue Q){
    PtrToNode FirstCell;
    int x;
    if (IsEmpty(Q)){
        printf("Empty queue\n");
    }
    else{
        FirstCell = Q->Head->next;
        x = FirstCell->data;
        Q->Head->next = Q->Head->next->next;
        free(FirstCell);
    }
    return x;
}


// Q1 is a queue of integers in increasing order
// Q2 is a queue of integers in decreasing order
void EnqueueSorted(Queue Sort_Q, Queue Q1, Queue Q2) {
    Stack S = CreateStack();

    // Transfer all elements from Q2 to the stack S
    while (!IsEmpty(Q2)) {
        Push(S, Dequeue(Q2));
    }

    // Continue merging until both Q1 and Q2 (now in stack S) are empty
    while (!IsEmpty(Q1) || !isEmpty(S)) {
        if (IsEmpty(Q1)) {
            Enqueue(Sort_Q, Pop(S));
        } else if (isEmpty(S)) {
            Enqueue(Sort_Q, Dequeue(Q1));
        } else if (Top(S) < top_Queue(Q1)) {
            Enqueue(Sort_Q, Pop(S));
        } else {
            Enqueue(Sort_Q, Dequeue(Q1));
        }
    }

    // Clean up remaining elements if any
    while (!isEmpty(S)) {
        Enqueue(Sort_Q, Pop(S));
    }
}



int main(){
    Queue Q1 = CreateQueue();
    Queue Q2 = CreateQueue();
    Queue Sort_Q = CreateQueue();
    Enqueue(Q1, 1);
    Enqueue(Q1, 5);
    Enqueue(Q1, 9);
    Enqueue(Q1, 40);
    
    Enqueue(Q2, 30);
    Enqueue(Q2, 25);
    Enqueue(Q2, 7);
    Enqueue(Q2, 5);
    Enqueue(Q2, 4);
    EnqueueSorted(Sort_Q, Q1, Q2);
    while (!IsEmpty(Sort_Q)){
        printf("%d ", Dequeue(Sort_Q));
    }
    free(Q1);
    free(Q2);
    return 0;
}