#include <stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Median of three pivot selection function
int medianOfThree(int A[], int left, int right) {
    int mid = left + (right - left) / 2;
    if (A[left] > A[mid]) {
        swap(&A[left], &A[mid]);
    }
    if (A[left] > A[right]) {
        swap(&A[left], &A[right]);
    }
    if (A[mid] > A[right]) {
        swap(&A[mid], &A[right]);
    }
    return mid; // Return the median element (middle index) as the pivot
}

// Partition function (using median-of-three pivot)
int Partition(int A[], int Left, int Right) {
    // Select median of three as the pivot
    int pivotIndex = medianOfThree(A, Left, Right);
    int pivot = A[pivotIndex];

    swap(&A[pivotIndex], &A[Right]); // Move pivot to the end for easier partitioning

    int i = Left - 1; // Index of element smaller than pivot
    int j = Left;     // Index to iterate through the array

    while (j < Right) {
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
        j++;
    }

    swap(&A[i + 1], &A[Right]); // Move pivot to its final position
    return i + 1;
}

// QuickSort function
void QuickSort(int A[], int Left, int Right) {
    if (Left < Right) {
        int pivotIndex = Partition(A, Left, Right);

        // Recursively call quickSort() for left and right subarrays
        QuickSort(A, Left, pivotIndex - 1);
        QuickSort(A, pivotIndex + 1, Right);
    }
}

int main() {
    int A[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    QuickSort(A, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
