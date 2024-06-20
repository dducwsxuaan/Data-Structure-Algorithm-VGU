#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTUDENTS 100  // maximum number of students
typedef struct {
    int student_id;
    char *full_name;
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
    printf("Enter the gpa: ");
    scanf("%f", &s->gpa);
}

