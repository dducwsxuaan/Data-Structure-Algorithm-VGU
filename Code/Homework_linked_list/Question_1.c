#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[100];
    int student_id;
    float gpa;
};

struct Node {
    struct Student data;
    struct Node* next;
};

typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List createEmptyLinkedList() {
    return NULL;
}

void printListSize(List head){
    int count = 0;
    Position temp = head;
    while (temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("The size of the linked list: %d\n", count);
}

void printList(List head){
    Position temp = head;
    while(temp != NULL){
        printf("Name: %s\t", temp->data.name);
        printf("Student ID: %d\t", temp->data.student_id);
        printf("GPA: %.2f\n", temp->data.gpa);
        temp = temp->next;
    }
    printf("NULL\n");
}

List insertAtBeginning(List head, struct Student student){
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
    new_node->data = student;
    new_node->next = head;
    head = new_node;
    return head;
}

List insertAtEnd(List head, struct Student student){
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
    new_node->data = student;
    new_node->next = NULL;
    if (head == NULL){
        head = new_node;
    }
    else{
        Position temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

List delete_StudentID(List head, int id){
    Position temp = head;
    Position prev = NULL;
    while (temp != NULL && temp->data.student_id != id){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        return head;
    }
    if (prev == NULL){
        head = head->next;
    }
    else{
        prev->next = temp->next;
    }
    free(temp);
    return head;
}

List delete_StudentName(List head, char* name){
    Position temp = head;
    Position prev = NULL;

    while (temp != NULL && strcmp(temp->data.name, name) == 0){
        head = temp->next;
        free(temp);
        temp = head;
    }
    while (temp != NULL && strcmp(temp->data.name, name) != 0){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        return head;
    }
    if (prev == NULL){
        head = head->next;
    }
    else{
        prev->next = temp->next;
    }
    free(temp);
    return head;
}

List exitList(List head){
    Position temp = head;
    while (temp != NULL){
        Position next = temp->next;
        free(temp);
        temp = next;
    }
    return NULL;
}

int main(){
    // List head = createEmptyLinkedList();
    // struct Student student1 = {"Alice", 1, 3.5};
    // struct Student student2 = {"Bob", 2, 3.0};
    // struct Student student3 = {"Charlie", 3, 2.5};
    // struct Student student4 = {"David", 4, 3.0};
    // struct Student student5 = {"Eve", 5, 3.5};
    // struct Student student6 = {"Bob", 6, 2.0};

    // head = insertAtBeginning(head, student1);
    // head = insertAtBeginning(head, student2);
    // head = insertAtBeginning(head, student3);
    // head = insertAtBeginning(head, student4);
    // head = insertAtBeginning(head, student5);
    // head = insertAtBeginning(head, student6);

    // printList(head);
    // printListSize(head);

    // head = delete_StudentID(head, 3);
    // printList(head);
    // printListSize(head);

    // head = delete_StudentName(head, "Bob");
    // printList(head);
    // printListSize(head);


    int choice;
    char name[100];
    int student_id;
    float gpa;
    List head = NULL;
    struct Student* new_student = malloc(sizeof(struct Student));
    while (1){
       printf("\nMenu:\n");
       printf("1. Create an empty linked list\n");
       printf("2. Print the number of elements in the linked list\n");
       printf("3. Print all nodes of list\n");
       printf("4. Enter information of a student and add this student at the beginning of the list\n");
       printf("5. Enter information of a student and add this student at the end of the list\n");
       printf("6. Enter the student ID and delete the student with that ID\n");
       printf("7. Enter the name of the student and delete the students with that name\n");
       printf("8. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);
        switch (choice){
            case 1:
                head = createEmptyLinkedList();
                break;
            case 2:
                printListSize(head);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Enter the name of the student: ");
                scanf(" %[^\n]s", name);
                printf("Enter the student ID: ");
                scanf("%d", &student_id);
                printf("Enter the GPA: ");
                scanf("%f", &gpa);

                strcpy(new_student->name, name);
                new_student->student_id = student_id;
                new_student->gpa = gpa;
                head = insertAtBeginning(head,*new_student);
                break;
            case 5:
                printf("Enter the name of the student: ");
                scanf("%[^\n]s", name);
                printf("Enter the student ID: ");
                scanf("%d", &student_id);
                printf("Enter the GPA: ");
                scanf("%f", &gpa);

                strcpy(new_student->name, name);
                new_student->student_id = student_id;
                new_student->gpa = gpa;
                head = insertAtEnd(head,*new_student);
                break;
            case 6:
                printf("Enter the student ID: ");
                scanf("%d", &student_id);
                head = delete_StudentID(head, student_id);
                break;
            case 7:
                printf("Enter the name of the student: ");
                scanf("%[^\n]s", name);
                head = delete_StudentName(head, name);
                break;
            case 8:
                head = exitList(head);
                return 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}

