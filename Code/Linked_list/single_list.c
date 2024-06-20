#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};  
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List head = NULL;

List createEmptyList(){
    return NULL;
}

PtrToNode createNode(int data){
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

List insertAtBeginning(int data){
    struct Node* new_node = createNode(data);
    if (head == NULL){
        head = new_node;
    }
    else{
        new_node->next = head;
        head = new_node;
    }
    return head;
}


List insertAtEnd(int data){
    struct Node* new_node = createNode(data);
    struct Node* temp = head;
    if (head == NULL){
        head = new_node;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

void deleteNode(int position){
    struct Node* temp = head;
    if (head == NULL){
        return;
    }
    if (position == 0){
        head = head->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++){
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL){
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void access_pos(int position){
    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position; i++){
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Invalid position\n");
    }
    else{
        printf("Data at position %d is %d\n", position, temp->data);
    }
}

void access_element(int data){
    struct Node* temp = head;
    int position = 0;
    while (temp != NULL){
        if (temp->data == data){
            printf("Data %d found at position %d\n", data, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Data %d not found\n", data);
}

void printList(){
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    head = createEmptyList();
    head = insertAtBeginning(1);
    head = insertAtBeginning(2);
    head = insertAtEnd(3);
    head = insertAtEnd(4);
    printList();        // 2 1 3 4
    deleteNode(1);
    printList();        // 2 3 4
    return 0;
}

