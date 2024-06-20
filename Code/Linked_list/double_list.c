#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
typedef struct Node* PtrToNode;
typedef struct Node* List;
 
List head = NULL;
List tail = NULL;
List createEmptyList(){
   return NULL;
}

PtrToNode createNode(int data){
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
List insertAtBeginning(int data){
    struct Node* new_node = createNode(data);
    if (head == NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    return head;
}

List insertAtEnd(int data){
    struct Node* new_node = createNode(data);
    if (tail == NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    return tail;
}

void deleteNode(int position){
    struct Node* temp = head;
    if (head == NULL){
        return;
    }
    if (position == 0){
        head = head->next;
        head->prev = NULL;
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
    next->prev = temp;
}

void access_pos(int position){
    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position; i++){
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Out of range\n");
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

void printList_forward(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printList_backward(){
    struct Node* temp = tail;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void findNode(int data){
    struct Node* temp = head;
    int position = 0;
    while(temp != NULL){
        if (temp->data == data){
            printf("Found at position %d\n", position);
        }
        temp = temp->next;
        position++;
    }
}


int main(){
    List head = createEmptyList();
    List tail = createEmptyList();
    head = insertAtBeginning(1);
    head = insertAtBeginning(4);
    head = insertAtBeginning(3);
    tail = insertAtEnd(4);
    tail = insertAtEnd(5);
    tail = insertAtEnd(6);
    printList_forward();
    printList_backward();
    deleteNode(2);
    printList_forward();
    printList_backward();
    findNode(4);
    return 0;
}