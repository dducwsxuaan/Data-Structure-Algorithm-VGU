#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // If the list is empty, make the new node as the head and point its next to itself
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    } else {
        // Find the last node in the list
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        // Make the new node as the new head and point its next to the previous head
        newNode->next = *head;

        // Make the last node point to the new head
        last->next = newNode;

        // Update the head pointer
        *head = newNode;
    }
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning of the circular linked list
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Display the circular linked list
    printf("Circular linked list: ");
    display(head);

    return 0;
}