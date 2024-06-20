#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXWORKERS 100 // Maximum number of workers

typedef struct{
    int id;
    char *fullname;
    int age;
    float salary;
} Worker;

/**
 * Function: inputWorker
 * ---------------------
 * Reads the details of a worker from the user.
 *
 * @param w: Pointer to a Worker structure.
 *
 * @return: void
 */
void inputWorker(Worker *w){
    printf("Enter the id: ");
    scanf("%d", &w->id);
    printf("Enter the name: ");
    char name[100];
    scanf("%s", name);
    w->fullname = (char *)malloc(strlen(name) + 1);
    strcpy(w->fullname, name);
    printf("Enter the age: ");
    scanf("%d", &w->age);
    printf("Enter the salary: ");
    scanf("%f", &w->salary);
}

/**
 * Function: printWorker
 * ---------------------
 * Prints the details of a worker to the console.
 *
 * @param w: Pointer to a Worker structure.
 *
 * @return: void
 */
void printWorker(Worker *w){
    printf("ID: %d\t", w->id);
    printf("Name: %s\t", w->fullname);
    printf("Age: %d\t", w->age);
    printf("Salary: %.2f\n", w->salary);
}

/**
 * Function: inputMultipleWorkers
 * ------------------------------
 * Reads the details of multiple workers from the user.
 *
 * @param workers: Pointer to an array of Worker structures.
 * @param N: Pointer to the number of workers.
 *
 * @return: void
 */
void inputMultipleWorkers(Worker *workers, int *N){
    for (int i = 0; i < *N; i++){
        printf("Enter the details of worker %d: \n", i+1);
        inputWorker(&workers[i]);
    }
}

/**
 * Function: Salarysum
 * -------------------
 * Computes and prints the sum of the salaries of all workers.
 *
 * @param workers: Pointer to an array of Worker structures.
 * @param N: Pointer to the number of workers.
 *
 * @return: void
 */
void Salarysum(Worker *workers, int *N){
    float sum = 0;
    for (int i = 0; i < *N; i++){
        sum += workers[i].salary;
    }
    printf("The sum of all salaries is: %.2f\n", sum);
}

void Swap(float *x, float *y){
    float temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * Function: sortdescending
 * ------------------------
 * Sorts the workers in descending order of their salaries and prints the details of the workers.
 *
 * @param w: Pointer to an array of Worker structures.
 * @param n: Pointer to the number of workers.
 *
 * @return: void
 */
void sortdescending(Worker *w, int *n){
    for (int i = 0; i < (*n)-1; i++){
        for (int j = i+1; j < (*n); j++){
            if (w[i].salary < w[j].salary){
                Swap(&w[i].salary, &w[j].salary);
                Swap(&w[i].id, &w[j].id);
                Swap(&w[i].age, &w[j].age);
                char *temp = w[i].fullname;
                w[i].fullname = w[j].fullname;
                w[j].fullname = temp;
            }
        }
    }
    printf("The details of the workers after sorting: \n");
    for (int i = 0; i < *n; i++){
        printWorker(&w[i]);
    }
}

int main(){
    int N;  // Number of workers
    printf("Enter the number of workers: ");
    scanf("%d", &N);
    Worker workers[MAXWORKERS];
    inputMultipleWorkers(workers, &N);
    printf("The details of the workers are: \n");
    for (int i = 0; i < N; i++){
        printWorker(&workers[i]);
    }
    Salarysum(workers, &N);
    sortdescending(workers, &N);
    return 0;
}
