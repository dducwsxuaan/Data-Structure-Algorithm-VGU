#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node* PtrToNode;

struct queue {
    PtrToNode Head;
    PtrToNode Tail;
};
typedef struct queue *Queue;

Queue CreateQueue(){
    Queue Q = malloc(sizeof(struct queue));
    Q->Head = malloc(sizeof(struct Node));
    Q->Head->next = NULL;
    Q->Tail = Q->Head;
    return Q;
}

// Enqueue is similar to push
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



int main(){
    Queue Q = CreateQueue();
    Enqueue(Q, 3);
    Enqueue(Q, 5);
    Enqueue(Q, 2);
    Enqueue(Q, 15);
    Enqueue(Q, 42);
    Dequeue(Q);
    Dequeue(Q);
    Enqueue(Q, 14);
    Enqueue(Q, 7);
    Dequeue(Q);
    Enqueue(Q, 9);
    Dequeue(Q); 
    Dequeue(Q);
    Enqueue(Q, 51);
    Dequeue(Q);
    //Dequeue(Q);
    // printf("%d\n", Dequeue(Q));
    // printf("%d\n", Dequeue(Q));
    // printf("%d\n", Dequeue(Q));
    printf("%d\n", Dequeue(Q));
    return 0;
}