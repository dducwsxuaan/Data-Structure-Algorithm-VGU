#include <stdio.h>
#include <stdlib.h>

struct doubleNode{
    int data;
    struct doubleNode *next;
    struct doubleNode *prev;
};

typedef struct doubleNode* PtrToDoubleNode;

void insert_End(PtrToDoubleNode DL_head, int X){
    struct doubleNode *newNode = (struct doubleNode*)malloc(sizeof(struct doubleNode));
    newNode->data = X;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (DL_head == NULL){
        DL_head = newNode;
    }
    else{
        struct doubleNode *temp = DL_head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printDoubleList(PtrToDoubleNode DL_head){
    struct doubleNode *temp = DL_head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

int main(){
    struct doubleNode *DL_head = NULL;
    insert_End(DL_head, 1);
    insert_End(DL_head, 2);
    insert_End(DL_head, 3);
    insert_End(DL_head, 4);
    insert_End(DL_head, 5);
    printDoubleList(DL_head);
    return 0;
}