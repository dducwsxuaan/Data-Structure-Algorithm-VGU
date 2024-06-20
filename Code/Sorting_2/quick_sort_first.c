#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function 
int Partition(int A[], int Left, int Right){
    // initialize pivot to be the first element
    int pivot = A[Left];
    int i = Left;
    int j = Right;
    while (i < j){
        // condition 1: find the first element greater than 
        // the pivot (from starting)
        do {
            i++;
        } while (A[i] <= pivot);

        // condition 2: find the first element smaller than 
        // the pivot (from last)
        do {
            j--;
        } while (A[j] > pivot);

        if (i < j){
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[Left], &A[j]);
    return j;
}

// QuickSort function 
void QuickSort(int A[], int Left, int Right){
    if (Left < Right){

        // call Partition function to find Partition Index
        int pivotIndex = Partition(A, Left, Right);

        // Recursively call quickSort() for left and right 
        // half based on partition Index
        QuickSort(A, Left, pivotIndex);
        QuickSort(A, pivotIndex + 1, Right);
    }
}   

void PrintArray(int A[], int N){
    for (int i = 0; i < N; i++){
        printf("%d ", A[i]);
    }
}
int main(){
    // int A[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int A[] = {0,1,1,0,1,2,1,2,0,0,0,1};
    int N = sizeof(A) / sizeof(int);
    printf("Before Sorting: ");
    PrintArray(A, N);
    QuickSort(A, 0, N);
    printf("\n");
    printf("After Sorting: ");
    PrintArray(A, N);
    return 0;
}