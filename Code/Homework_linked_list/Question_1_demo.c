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

void deleteLinkedList(List head) {
    Position temp = head;
    Position next;

    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
}

List createLinkedList() {
    return NULL;
}

void push_back(struct Node* head, struct Student student){
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
    new_node->data.gpa = student.gpa;
    strcpy(new_node->data.name, student.name);
    new_node->data.student_id = student.student_id;
    new_node->next = NULL;

    struct Node* temp = head;
    if (temp == NULL){
        head = new_node;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void inputNode(struct Student *student){
        printf("\n");
        printf("Enter the name: ");
        scanf("%s", student->name);
        student->name[sizeof(student->name) - 1] = '\0';
        printf("Enter student id: ");
        scanf("%d", &(student->student_id));
        printf("Enter the gpa: ");
        scanf("%f", &(student->gpa));
        printf("\n");
}

struct Node* insertToNode_End(struct Student student, List head){
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
    strcpy(new_node->data.name, student.name);
    new_node->data.student_id = student.student_id;
    new_node->data.gpa = student.gpa;
    new_node->next = NULL;
    if (head == NULL){
        head = new_node;
    }
    else{
        struct Node* temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}

struct Node* insertToNode_Begin(struct Student student, List head){
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
    new_node->data = student;
    new_node->next = head;
    head = new_node;
    return head;
}


void delete_student_id(List head, int id){
    if (head == NULL) return;
    Position temp = head;
    
    if (temp->data.student_id == id){
        head = temp->next;
        free(temp);
        return;
    }
    while (temp->next != NULL && temp->next->data.student_id != id){
        temp = temp->next;
    }
    if (temp->next == NULL){
        return;
    }
    Position DeleteNode = temp->next;
    temp->next = DeleteNode->next;
    free(DeleteNode);
}

void delete_student_name(List head, const char* name){
    if (head == NULL) return;
    Position temp = head;
    
    // Check if the first node matches the given name
    while (temp != NULL && strcmp(temp->data.name, name) == 0){
        head = temp->next;
        free(temp);
        temp = head;
    }
    
    // Traverse the linked list and delete nodes with matching names
    while (temp != NULL && temp->next != NULL){
        if (strcmp(temp->next->data.name, name) == 0){
            Position deleteNode = temp->next;
            temp->next = deleteNode->next;
            free(deleteNode);
        }
        else{
            temp = temp->next;
        }
    }
}

void display_all_nodes(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL){
        printf("(%s, ", temp->data.name);
        printf("%d, ", temp->data.student_id);
        printf("%0.2f )", temp->data.gpa);
        printf(" -> ");
        temp = temp->next;
    }
    printf("NULL\n");
}



// Sort the linked list in descending order of GPA using Bubble Sort
void swap(struct Node* a, struct Node* b){
    struct Student temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void sort_descending(struct Node* head){
    struct Node* temp;
    struct Node* temp2;
    for (temp = head; temp != NULL; temp = temp->next){
        for (temp2 = temp->next; temp2 != NULL; temp2 = temp2->next){
            if (temp->data.gpa < temp2->data.gpa){
                swap(temp, temp2);
            }
        }
    }
}


// // Sort the linked list in descending order of GPA using Quick Sort
// struct Node* partition(struct Node* head, struct Node* end, struct Node** newHead, struct Node** newEnd){
//     struct Node* pivot = end;
//     struct Node* prev = NULL;
//     struct Node* temp = head;
//     struct Node* tail = pivot;

//     while (temp != pivot){
//         if (temp->data.gpa > pivot->data.gpa){
//             if ((*newHead) == NULL){
//                 (*newHead) = temp;
//             }
//             prev = temp;
//         }
//         temp = temp->next;

//         if (prev != NULL){
//             prev->next = temp;
//         }
//     }
//     if ((*newHead) == NULL){
//         (*newHead) = pivot;
//     }
//     (*newEnd) = tail;
//     return pivot;
// }

// void quickSort(struct Node* head, struct Node* end){
//     if (head == NULL || head == end || head == end->next) return;

//     struct Node* newHead = NULL;
//     struct Node* newEnd = NULL;

//     struct Node* pivot = partition(head, end, &newHead, &newEnd);

//     if (newHead != pivot){
//         struct Node* temp = newHead;
//         while (temp->next != pivot){
//             temp = temp->next;
//         }
//         temp->next = NULL;
//         quickSort(newHead, temp);
//         temp = temp->next;
//         temp->next = pivot;
//     }
//     quickSort(pivot->next, newEnd);
// }

void empty_list(List a)
{
    if (a==NULL){
        PtrToNode head = (struct Node*) malloc (sizeof(struct Node));
        a = head;
    }
    else{
        PtrToNode temp = a;
        PtrToNode next;
        while (temp != NULL){
            next = temp->next;
            free(temp);
            temp = next;
        }
    }   
}

int main(){
    struct Node* head = NULL;
    struct Student student1 = {"Alice", 1, 3.5};
    struct Student student2 = {"Bob", 2, 3.0};
    struct Student student3 = {"Charlie", 3, 3.2};
    struct Student student4 = {"David", 4, 3.8};
    struct Student student5 = {"Eve", 5, 3.9};
    insertToNode_End(student1, head);
    insertToNode_End(student2, head);
    insertToNode_End(student3, head);
    insertToNode_End(student4, head);
    insertToNode_End(student5, head);
    display_all_nodes(NULL);
    return 0;
}
