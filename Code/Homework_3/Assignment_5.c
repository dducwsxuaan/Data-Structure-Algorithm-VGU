#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSTUDENTS 100  // maximum number of students

typedef struct {
    int student_id;
    char *full_name;
    int age;
    float gpa;
} Student;

void inputStudent(Student *s){
    printf("Enter the id: ");
    scanf("%d", &s->student_id);
    printf("Enter the name: ");
    char name[100];
    scanf("%s", name);
    s->full_name = (char *)malloc(strlen(name) + 1);
    strcpy(s->full_name, name);
    printf("Enter the age: ");
    scanf("%d", &s->age);
    printf("Enter the gpa: ");
    scanf("%f", &s->gpa);
}

void printStudent(Student *s){
    printf("ID: %d\t", s->student_id);
    printf("Name: %s\t", s->full_name);
    printf("Age: %d\t", s->age);
    printf("GPA: %.3f\n", s->gpa);
}

void inputMultipleStudents(Student* students, int *N){
    for (int i = 0; i < *N; i++){
        printf("Enter the information of student %d: \n", i+1);
        inputStudent(&students[i]);
    }
}


void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sort Algorithm for descending order

// Median of three pivot selection function
int medianOfThree(Student A[], int left, int right) {
    int mid = left + (right - left) / 2;
    if (A[left].gpa < A[mid].gpa) {
        swap(&A[left], &A[mid]);
    }
    if (A[left].gpa < A[right].gpa) {
        swap(&A[left], &A[right]);
    }
    if (A[mid].gpa < A[right].gpa) {
        swap(&A[mid], &A[right]);
    }
    return mid; // Return the median element (middle index) as the pivot
}

// Partition function (using median-of-three pivot)
int Partition(Student A[], int Left, int Right) {
    // Select median of three as the pivot
    int pivotIndex = medianOfThree(A, Left, Right);
    float pivot = A[pivotIndex].gpa;

    swap(&A[pivotIndex], &A[Right]); // Move pivot to the end for easier partitioning

    int i = Left - 1; // Index of element smaller than pivot
    int j = Left;     // Index to iterate through the array

    while (j < Right) {
        if (A[j].gpa >= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
        j++;
    }

    swap(&A[i + 1], &A[Right]); // Move pivot to its final position
    return i + 1;
}

// QuickSort function
void QuickSort(Student A[], int Left, int Right) {
    if (Left < Right) {
        int pivotIndex = Partition(A, Left, Right);

        // Recursively call quickSort() for left and right subarrays
        QuickSort(A, Left, pivotIndex - 1);
        QuickSort(A, pivotIndex + 1, Right);
    }
}


int main(){
    Student students[MAXSTUDENTS];
    int N;
    printf("Enter the number of students: ");
    scanf("%d", &N);
    inputMultipleStudents(students, &N);
    for (int i = 0; i < N; i++){
        printf("Information of student %d: \n", i+1);
        printStudent(&students[i]);
    }

    printf("Before Sorting: \n");
    for (int i = 0; i < N; i++){
        printStudent(&students[i]);
    }
    printf("\n");

    // Sort the students based on their GPA in descending order
    QuickSort(students, 0, N - 1);

    printf("After Sorting: \n");
    for (int i = 0; i < N; i++){
        printStudent(&students[i]);
    }
    return 0;
}
