#include <stdio.h>
#include <stdlib.h>

// Function to sort using bucket sort
void bucketSort(int array[], int n) {
    // Create n empty buckets
    int max_value = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }
    int bucket_count = max_value / 10 + 1;
    int** buckets = (int**)malloc(bucket_count * sizeof(int*));
    int* bucket_sizes = (int*)calloc(bucket_count, sizeof(int));
    
    // Initialize each bucket as empty
    for (int i = 0; i < bucket_count; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
    }
    
    // Put elements into the buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = array[i] / 10;
        buckets[bucket_index][bucket_sizes[bucket_index]] = array[i];
        bucket_sizes[bucket_index]++;
    }
    
    // Sort elements within each bucket using insertion sort
    for (int i = 0; i < bucket_count; i++) {
        for (int j = 1; j < bucket_sizes[i]; j++) {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }
    
    // Concatenate the sorted buckets
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        for (int j = 0; j < bucket_sizes[i]; j++) {
            array[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_sizes);
}

// Function to print an array
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int n = sizeof(array) / sizeof(array[0]);
    
    printf("Original array: ");
    printArray(array, n);
    
    bucketSort(array, n);
    
    printf("Sorted array: ");
    printArray(array, n);
    
    return 0;
}