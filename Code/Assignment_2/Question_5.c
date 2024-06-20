#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    char data;
    struct Node* next;
};

// Structure for a stack
struct Stack {
    struct Node* top;
};

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push a character onto the stack
void push(struct Stack* stack, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    struct Node* temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to check if a word is inversible
bool isWordInversible(struct Node* head) {
    // Base case: an empty list or a single character is always inversible
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // Create a stack
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;

    // Push each character of the word onto the stack
    struct Node* temp = head;
    while (temp != NULL) {
        push(stack, temp->data);
        temp = temp->next;
    }

    // Compare the original word with the reversed word
    temp = head;
    while (temp != NULL) {
        char data = pop(stack);
        if (temp->data != data) {
            return false;
        }
        temp = temp->next;
    }

    return true;
}

// Function to create a new node in the linked list
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Create a sample linked list
    char word[] = "hannah";
    struct Node* head = NULL;
    for (int i = 0; i < sizeof(word) - 1; i++) {
        struct Node* newNode = createNode(word[i]);
        newNode->next = head;
        head = newNode;
    }

    // Check if the word is inversible
    if (isWordInversible(head)) {
        printf("The word is inversible.\n");
    } else {
        printf("The word is not inversible.\n");
    }
    free(head); // Free the memory allocated for the linked list

    return 0;
}
